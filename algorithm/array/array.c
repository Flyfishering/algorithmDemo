//
//  array.c
//  algorithm
//
//  Created by wangbinbin on 2019/1/10.
//  Copyright © 2019 wangbinbin. All rights reserved.
//

#include "array.h"
#include <stdlib.h>
#include <string.h>

struct array {
    int size; // 数组的总容量
    int used; // 数组中已经占用的容量
    int *arr;// 数组的头地址
};
// 打印整个数组
void dump(struct array *array)
{
    int idx;
    
    for (idx = 0; idx < array->used; idx++)
        printf("[%02d]: %08d\n", idx, array->arr[idx]);
}
// 初始化 数组
void alloc(struct array *array)
{
    array->arr = (int *)malloc(array->size * sizeof(int));
}
// 数组中插入元素
int insert(struct array *array, int elem)
{
    int idx;
    // 数组满载 退出
    if (array->used >= array->size)
        return -1;
    // 找到比 elem 大的位置
    for (idx = 0; idx < array->used; idx++) {
        if (array->arr[idx] > elem)
            break;
    }
    // 将 idx 到 used 之间的元素依次往后移一位
    if (idx < array->used)
        memmove(&array->arr[idx+1], &array->arr[idx],
                (array->used - idx) * sizeof(int));
    // 将 elem 插入到 idx 位置
    array->arr[idx] = elem;
    // 数组已使用大小 used + 1
    array->used++;
    return idx;
}
// 删除元素
int delete(struct array *array, int idx)
{
    // 判断 idx 是否是非法
    if (idx < 0 || idx >= array->used)
        return -1;
    // 将 idx+1 后面所有的内容依次向前移动一位
    memmove(&array->arr[idx], &array->arr[idx+1],
            (array->used - idx) * sizeof(int));
    array->used--;
    return 0;
}
// 查找 elem 的位置
int search(struct array *array, int elem)
{
    int idx;
    
    for (idx = 0; idx < array->used; idx++) {
        if (array->arr[idx] == elem)
            return idx;
        if (array->arr[idx] > elem)
            return -1;
    }
    
    return -1;
}

int testArr()
{
    int idx;
    struct array ten_int = {10, 0, NULL};

    alloc(&ten_int);
    if (!ten_int.arr)
        return -1;
    insert(&ten_int, 1);
    insert(&ten_int, 3);
    insert(&ten_int, 2);
    printf("=== insert 1, 3, 2\n");
    dump(&ten_int);

    idx = search(&ten_int, 2);
    printf("2 is at position %d\n", idx);
    idx = search(&ten_int, 9);
    printf("9 is at position %d\n", idx);

    printf("=== delete [6] element \n");
    delete(&ten_int, 6);
    dump(&ten_int);
    printf("=== delete [0] element \n");
    delete(&ten_int, 0);
    dump(&ten_int);
    return 0;
}
