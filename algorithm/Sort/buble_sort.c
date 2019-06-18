//
//  buble_sort.c
//  algorithm
//
//  Created by wangbinbin on 2019/1/21.
//  Copyright © 2019 wangbinbin. All rights reserved.
//

#include "buble_sort.h"
#include <stdlib.h>
#include <stdbool.h>
#include "sort_base.h"
/// 冒泡排序
void bubble_sort(struct array *array)
{
    int i, j;
    
    if (array->used <= 1)
        return;
    
    for (i = 0; i < array->used; i++) {
        bool has_swap = false;
        for (j = 0; j < array->used - i - 1; j++) {
            if (array->arr[j] > array->arr[j+1]) {
                int tmp;
                tmp = array->arr[j];
                array->arr[j] = array->arr[j+1];
                array->arr[j+1] = tmp;
                has_swap = true;
            }
            
        }
        if (!has_swap)
            break;
    }
}

void bubble_sort_test()
{
    int idx;
    struct array ten_int = {10, 0, NULL};
    
    alloc(&ten_int);
    for (idx = 0; idx < 10; idx++)
        ten_int.arr[idx] = 30 - idx;
    ten_int.used = 10;
    dump(&ten_int);
    bubble_sort(&ten_int);
    dump(&ten_int);
}



