//
//  array.h
//  algorithm
//
//  Created by wangbinbin on 2019/1/10.
//  Copyright © 2019 wangbinbin. All rights reserved.
//

#ifndef array_h
#define array_h

#include <stdio.h>
struct array {
    int size;
    int used;
    int *arr;
};
void alloc(struct array *array);
// 打印数组
void dump(struct array *array);
int testArr();
#endif /* array_h */

