
//
//  binary_search.c
//  algorithm
//
//  Created by wangbinbin on 2019/1/22.
//  Copyright © 2019 wangbinbin. All rights reserved.
//

#include "binary_search.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int(*bs)(int *arr, int size, int val);

// 二分查找 递归实现
int binary_search_r(int *arr, int size, int val)
{
    int mid = size / 2;
    int idx;
    // 查找到正确的值
    if (arr[mid] == val)
        return mid;
    
    // mid == 0 means size == 1
    // so the only element in array doesn't equal to val
    if (!mid) // 当 mid = 0 时，说明 数组大小为 1；直接退出
        return -1;
    
    if (arr[mid] < val) {
        idx = binary_search_r(arr + mid + 1, size - mid - 1, val);
        if (idx != -1)
            idx += mid + 1;
    } else {
        idx = binary_search_r(arr, mid, val);
    }
    
    return idx;
}
// 二分查找 循环实现
int binary_search_i(int *arr, int size, int val)
{
    int low = 0, high = size - 1, mid;
    
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == val)
            return mid;
        
        if (arr[mid] < val)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return -1;
}
// 测试二分查找
void iteratioin_test(bs binary_search)
{
    int arr[10] = {1, 4, 5, 9, 12, 19, 21, 28, 31, 36};
    int idx;
    
    idx = binary_search(arr, 10, 12);
    if (idx != -1)
        printf("find 12 at %d\n", idx);
    else
        printf("12 not in arr \n");
    
    idx = binary_search(arr, 10, 13);
    if (idx != -1)
        printf("find 13 at %d\n", idx);
    else
        printf("13 not in arr \n");
    
    idx = binary_search(arr, 10, 1);
    if (idx != -1)
        printf("find 1 at %d\n", idx);
    else
        printf("1 not in arr \n");
    
    idx = binary_search(arr, 10, 36);
    if (idx != -1)
        printf("find 36 at %d\n", idx);
    else
        printf("36 not in arr \n");
    
    idx = binary_search(arr, 10, 31);
    if (idx != -1)
        printf("find 31 at %d\n", idx);
    else
        printf("31 not in arr \n");
    
}
// 分别测试 两种二分查找方法e
int binary_search_test()
{
    printf("=== Test iteration version:\n");
    iteratioin_test(binary_search_i);
    
    printf("=== Test recursive version:\n");
    iteratioin_test(binary_search_r);
    
    return 0;
}
