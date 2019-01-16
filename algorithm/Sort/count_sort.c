//
//  count_sort.c
//  algorithm
//
//  Created by wangbinbin on 2019/1/16.
//  Copyright © 2019 wangbinbin. All rights reserved.
//

#include "count_sort.h"
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
//计数排序  即桶排序
void count_sort_dump(int a[],int size)
{
    int i = 0;
    
    printf("\r\n");
    
    for(i = 0; i <size; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\r\n");
}

/*计数排序，时间复杂度0（n)，非原地排序
 *计数排序也是利用桶排序的解决方式
 * 如果数组最大值max比数组大小size大很多不适合；
 * 计数排序要求时非负整数
 * */
void count_sort(int a[],int size)
{
    int i = 0;
    int max = 0;
    int *count = 0;
    int *res = 0;
    
    /*找到最大数*/
    for (i = 0 ; i< size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    
    count = (int *)malloc(sizeof(int)*(max + 1));
    assert(count != NULL);
    
    memset(count,0,sizeof(int)*(max + 1));
    
    /*计数*/
    for (i = 0; i < size;i++)
    {
        count[a[i]]++;
    }
    
    /*依次累加*/
    for(i = 1 ;i <= max; i ++)
    {
        count[i] += count[i-1];
    }
    
    res = (int *)malloc(sizeof(int)*(size));
    assert(res != NULL);
    /*核心代码，count[a[i] - 1]就是排序好的下标*/
    for (i = size-1;i >= 0; i--)
    {
        res[count[a[i]] -1] = a[i];
        count[a[i]]--;
    }
    
    memcpy(a,res,size*(sizeof(int)));
    
    free(res);
    free(count);
    return;
}


int count_sort_test()
{
    int a [10]={1,5,6,8,10,9,3,1,2,1};
    printf("\r\n conunt sort test ....");
    count_sort(a,10);
    count_sort_dump(a,10);
    
    return 0;
}
