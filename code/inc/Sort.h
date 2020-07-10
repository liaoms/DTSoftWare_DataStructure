#ifndef __SORT_H__
#define __SORT_H__

#include "Object.h"

namespace LMSLib
{
template <typename T>

class Sort : public Object
{
private:
    static void swap(T& left, T& right)
    {
        T tmp = left;
        left = right;
        right = tmp;
    }

public:
    static void Insert(T array[], int len, bool min2max = true)
    {
        int index = -1;
        for(int i=1; i<len; i++)
        {
            index = i;
            T tmp = array[i];
            for(int j=i; j>0; j--)
            {
                if( min2max ? (tmp < array[j-1]) : (tmp > array[j-1]))
                {
                    array[j] = array[j - 1];
                    index = j - 1;
                }
            }

            if(index != i)
            {
                array[index] = tmp;
            }
        }
    }

    static void Select(T array[], int len, bool min2max = true)
    {
        for(int i=0; i<len; i++)
        {
            int index = i;
            for(int j=i+1; j<len; j++)
            {
                if( min2max ? (array[index] > array[j]) : (array[index] < array[j]) )
                {
                    index = j;
                }
            }

            if(index != i)
            {
                swap(array[index], array[i]);
            }
        }
    }

    static void Bubble(T array[], int len, bool min2max = true)
    {
        for(int i=0; i<len; i++)
        {
            for(int j=len-1; j>i; j--)
            {
                if( min2max ? (array[j] < array[j-1]) : (array[j] > array[j-1]) )
                {
                    swap(array[j], array[j-1]);
                }
            }
        }
    }

    static void ShellWithSelect(T array[], int len, bool min2max = true)
    {
        int d = len;
        do
        {
            d = d/3 + 1;
            for(int i=0; i<len; i += d)
            {
                int index = i;
                for(int j=i+d; j<len; j += d)
                {
                    if( min2max ? (array[index] > array[j]) : (array[index] < array[j]) )
                    {
                        index = j;                        
                    }
                }

                if(index != i)
                {
                    swap(array[index], array[i]);
                }
            }
        }while(d > 1);
    }

};

}

#endif // !__SORT_H__