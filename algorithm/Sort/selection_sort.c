//
//  selection_sort.c
//  algorithm
//
//  Created by wangbinbin on 2019/1/21.
//  Copyright © 2019 wangbinbin. All rights reserved.
//

#include "selection_sort.h"
#include <stdlib.h>
#include <stdbool.h>
#include "sort_base.h"

/// 选择排序
void selection_sort(struct array *array)
{
    int i, j;
    
    if (array->used <= 1)
        return;
    
    for (i = 0; i < array->used - 1; i++) {
        int tmp, idx = i;
        
        for (j = i + 1; j < array->used; j++)
            if (array->arr[j] < array->arr[idx])
                idx = j;
        
        if (idx == i)
            continue;
        
        tmp = array->arr[i];
        array->arr[i] = array->arr[idx];
        array->arr[idx] = tmp;
    }
}

void selection_sort_test()
{
    int idx;
    struct array ten_int = {10, 0, NULL};
    
    alloc(&ten_int);
    for (idx = 0; idx < 10; idx++)
        ten_int.arr[idx] = 30 - idx;
    ten_int.used = 10;
    dump(&ten_int);
    selection_sort(&ten_int);
    dump(&ten_int);
}
