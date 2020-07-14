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

    static void merger(T array[], int begin, int mid, int end, bool min2max=true)
    {
        int len = end - begin + 1;
        T buf[len];

        int nLeft = begin;
        int nRight = mid+1;
        int index = 0;
        while((nLeft <= mid) && (nRight <= end)) 
        {
            if( min2max ? (array[nLeft] < array[nRight]) : (array[nLeft] > array[nRight]))
            {
                buf[index++] = array[nLeft++];
            }
            else
            {
                buf[index++] = array[nRight++];
            }   
        }

        while(nLeft <= mid)
        {
            buf[index++] = array[nLeft++];
        }

        while(nRight <= end)
        {
            buf[index++] = array[nRight++];
        }

        for(int i=begin, index = 0; i<=end; i++, index++)
        {
            array[i] = buf[index];
        }
    }

    static void merger(T array[], int begin, int end, bool min2max = true)
    {
        if( end != begin)
        {
            int mid = (end + begin) / 2;
            merger(array, begin, mid, min2max);   //左半边排序
            merger(array, mid+1, end, min2max);   //右半边排序
            merger(array, begin, mid, end, min2max);    //合并两边
        }
    }

    static int partition(T array[], int low, int hight, bool min2max = true)
    {
        T tmp = array[low];   //获取基准数据
        while(low < hight)
        {
            //从右往左获取第一个比基准值 大 或 小的值, 做交换
            while( (low < hight) && (min2max ? (tmp < array[hight]):(tmp > array[hight])) )
            {
                hight--;
            }
            if(low < hight) //左右下标不相等时才交换，否则不需要交换
            {
                swap(array[low], array[hight]); 
            }
            
            //从左往右获取第一个比基准值 小 或大的值，做交换
            while ( (low < hight) && ( min2max ? (tmp > array[low]) : (tmp < array[low])) )
            {
                low++;
            }
            if(low < hight) //左右下标不相等时才交换，否则不需要交换
            {
                swap(array[low], array[hight]); 
            }
        }

        array[low] = tmp;
        return low;
    }

    static void Quick(T array[], int low, int hight, bool min2max = true)
    {  
        if(low < hight)
        {
            int index = partition(array, low, hight, min2max);  //获取位置,位置为值大小的分水岭
            Quick(array, low, index-1, min2max);        //最左边的列表快速排序
            Quick(array, index + 1, hight, min2max);    //对右边的列表快速排序
        }
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
        bool flag = true;
        for(int i=0; i<len; i++)
        {
            flag = true;
            for(int j=0; j<len-i-1; j++)
            {
                if( min2max ? (array[j] > array[j+1]) : (array[j] < array[j+1]) )
                {
                    swap(array[j], array[j+1]);
                    flag = false;
                }
            }

            if(flag)
            {
                break;
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

    static void ShellWithInsert(T array[], int len, bool min2max = true)
    {
        int d = len;
        do
        {
            d = d/3+ 1;

            for(int i=d; i<len; i += d)
            {
                int index = i;
                T tmp = array[index];

                for(int j=i; j>0; j -= d)
                {
                    if( min2max ? (tmp < array[j-d]) : (tmp > array[j-d]) )
                    {
                        array[j] = array[j-d];
                        index = j - d;
                    }
                }

                if(index != i)
                {
                    array[index] = tmp;
                }
            }
        } while (d > 1);      
    }

    static void ShellWithBubble(T array[], int len, bool min2max = true)
    {
        int d = len;

        do
        {
            bool flag = true;

            d = d/3 + 1;
            for(int i=0; i<len; i += d)
            {   
                flag = true;
                for(int j = 0; j < len -i-d; j += d)
                {
                    if( min2max ? (array[j] > array[j+d]) : (array[j] < array[j+d]) )
                    {
                        swap(array[j], array[j+d]);
                        flag = false;
                    }
                }
                if(flag)
                {
                    break;
                }
            }

        } while (d > 1);
    }

    static void merger(T array[], int len, bool min2max = true)
    {
        merger(array, 0, len-1, min2max);
    }

    static void Quick(T array[], int len, bool min2max = true)
    {
        Quick(array, 0, len-1, min2max);
    }
};

}

#endif // !__SORT_H__