//
//  insertion_sort.c
//  algorithm
//
//  Created by wangbinbin on 2019/1/21.
//  Copyright © 2019 wangbinbin. All rights reserved.
//

#include "insertion_sort.h"
#include <stdlib.h>
#include <stdbool.h>
#include "sort_base.h"
/// 插入排序
void insertion_sort(struct array *array)
{
    int i, j;
    
    if (array->used <= 1)
        return;
    
    for (i = 1; i < array->used; i++) {
        int val = array->arr[i];
        
        for (j = i - 1; j >= 0; j--) {
            if (val < array->arr[j])
                array->arr[j+1] = array->arr[j];
            else
                break;
        }
        array->arr[j+1] = val;
    }
}

void insertion_sort_test()
{
    int idx;
    struct array ten_int = {10, 0, NULL};
    
    alloc(&ten_int);
    for (idx = 0; idx < 10; idx++)
        ten_int.arr[idx] = 30 - idx;
    ten_int.used = 10;
    dump(&ten_int);
    insertion_sort(&ten_int);
    dump(&ten_int);
}
