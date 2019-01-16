//
//  quick_sort.c
//  algorithm
//
//  Created by wangbinbin on 2019/1/16.
//  Copyright © 2019 wangbinbin. All rights reserved.
//

#include "quick_sort.h"
void quick_sort_dump(int *arr, int size)
{
    int idx;
    
    for (idx = 0; idx < size; idx++)
        printf("%08d\n", arr[idx]);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *arr, int p, int r)
{
    //int pivot = arr[r];
    int i, j;
    
    i = j = p;
    
    for (; j < r; j++) {
        if (arr[j] < arr[r]) {
            if(i != j)
            {
                swap(arr + i, arr + j);
                
            }
            i++;
        }
    }
    
    swap(arr + i, arr + r);
    return i;
}

void __quick_sort(int *arr, int p, int r)
{
    int q;
    
    if (p >= r)
        return;
    
    q = partition(arr, p, r);
    __quick_sort(arr, p, q-1);
    __quick_sort(arr, q+1, r);
}

void quick_sort(int *arr, int size)
{
    __quick_sort(arr, 0, size - 1);
}

void quick_sort_test()
{
    int test[10] = {5, 8, 9, 23, 67, 1, 3, 7, 31, 56};
    
    quick_sort(test, 10);
    
    quick_sort_dump(test, 10);
}
