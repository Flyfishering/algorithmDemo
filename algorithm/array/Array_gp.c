//
//  Array_gp.c
//  algorithm
//
//  Created by wangbinbin on 2019/1/10.
//  Copyright © 2019 wangbinbin. All rights reserved.
//

#include "Array_gp.h"
#include <string.h>
#include <stdbool.h>
// 创建数组
Array* arrayCreate()
{
    struct Array *array = NULL;
    // 给 array 分配内存
    array = malloc(sizeof(*array));
    if (NULL == array)
    {
        return NULL;
    }
    
    // 初始化 array 内的元素
    array->p = NULL;
    
    array->size = 0;
    array->typeSize = 0;
    array->len = 0;
    
    array->dup = NULL;
    array->free = NULL;
    array->match = NULL;
    
    return array;
}

// 初始化 数组
void arrayInit(Array *array, int size, int typeSize)
{
    if (NULL == array
        || typeSize <= 0
        || size < 0)
    {
        return;
    }
    
    void *p = calloc(1, size* typeSize);
    if (NULL == p)
    {
        return;
    }
    
    array->p = p;
    array->len = 0;
    array->size = size;
    array->typeSize = typeSize;
}

int arrayInsert(Array *array, size_t pos, void *const value)
{
    // 异常处理
    if (NULL == array) // 数组为空
// 数组插入数据
    {
        return -1;
    }
    
    if (array->len >= array->size) // 数组已满
    {
        return -2;
    }
    
    if (pos > array->size || pos <= 0)// 数组越界
    { 
        return -3;
    }
    // 拿到数组起始指针地址

    char *pBegin = array->p;
    for (size_t i = array->len; i > pos - 1; --i)
    {
        void *pNew = pBegin + i * array->typeSize;
        void *pOld = pBegin + (i - 1) *array->typeSize;
        if (NULL != array->dup)
        {
            array->dup(pNew, pOld);
        }
        else
        {
            memcpy(pNew, pOld, array->typeSize);
        }
    }
    
    void *pCopy = (void*)(pBegin + ((pos - 1) * array->typeSize));
    if (NULL != array->dup)
    {
        array->dup(pCopy, value);
    }
    else
    {
        memcpy(pCopy, value, array->typeSize);
    }
    ++array->len;
    return 0;
}

size_t arraySearchValue(Array *array, void* const value)
{
    if (NULL == array)
    {
        return -1;
    }
    
    char *pBegin = array->p;
    size_t i = 0;
    for (; i < array->len; ++i)
    {
        int nCmp = 0;
        if (NULL != array->match)
        {
            nCmp = array->match(pBegin + i * array->typeSize, value);
        }
        else
        {
            nCmp = memcmp(pBegin + i * array->typeSize, value, array->typeSize);
        }
        
        if (nCmp == 0)
        {
            break;
        }
    }
    
    return i;
}

void* arrayIndex(Array *array, size_t index)
{
    if (NULL == array)
    {
        return NULL;
    }
    
    if (index > array->len
        || index <= 0)
    {
        return NULL;
    }
    
    char *pBegin = array->p;
    return pBegin + array->typeSize * (index - 1);
}

int arrayModify(Array *array, size_t pos, void *const value)
{
    if (NULL == array)
    {
        return -1;
    }
    if (pos > array->len
        || pos <= 0)
    {
        return -2;
    }
    
    char *pBegin = array->p;
    void *pOld = pBegin + (pos - 1) * array->typeSize;
    if (NULL != array->dup)
    {
        array->dup(pOld, value);
    }
    else
    {
        memcpy(pOld, value, array->typeSize);
    }
    
    return 0;
}

size_t arrayLen(Array *array)
{
    if (NULL == array)
    {
        return 0;
    }
    
    return array->len;
}

size_t arraySize(Array *array)
{
    if (NULL == array)
    {
        return 0;
    }
    
    return array->size;
}

void arrayEmpty(Array *array)
{
    if (NULL == array)
    {
        return;
    }
    
    free(array->p);
    array->p = NULL;
    free(array);
    array = NULL;
}

void arrayDelValue(Array *array, void *value)
{
    if (NULL == array)
    {
        return;
    }
    
    char* pBegin = array->p;
    bool bCopy = false;
    for (size_t i = 0; i < array->len; ++i)
    {
        if (!bCopy)
        {
            int nCmp = 0;
            if (NULL != array->match)
            {
                nCmp = array->match(pBegin + i * array->typeSize, value);
            }
            else
            {
                nCmp = memcmp(pBegin + i * array->typeSize, value, array->typeSize);
            }
            
            if (0 == nCmp)
            {
                bCopy = true;
                continue;
            }
        }
        else
        {
            void *pOld = pBegin + (i + 1) * array->typeSize;
            void *pNew = pBegin + i * array->typeSize;
            if (NULL != array->dup)
            {
                array->dup(pNew, pOld);
            }
            else
            {
                memcpy(pNew, pOld, array->typeSize);
            }
        }
    }
    
    if (bCopy)
    {
        --array->len;
    }
}

void arrayDelIndex(Array *array, size_t pos)
{
    if (NULL == array)
    {
        return;
    }
    
    if (pos > array->len || pos <= 0)
    {
        return;
    }
    
    char* pBegin = array->p;
    for (size_t i = pos - 1; i < array->len - 1; ++i)
    {
        void *pOld = pBegin + (i + 1) * array->typeSize;
        void *pNew = pBegin + i * array->typeSize;
        if (NULL != array->dup)
        {
            array->dup(pNew, pOld);
        }
        else
        {
            memcpy(pNew, pOld, array->typeSize);
        }
    }
    
    --array->len;
}

void dumpArr(struct Array *array)
{
    int idx;
    
    for (idx = 0; idx < array->len; idx++){
        int *t = array->p;
        printf("[%02d]: %08d\n", idx, t[idx]);
    }
    
}
struct single_list {
    // 指向下一个 链表单元的地址
    struct single_list *next;
    int val;
};

int testFunctionArray()
{
    struct single_list pseudo_head;
    
    
    
    Array *array = arrayCreate();
    arrayInit(array, 8, 8);
    int num1 = 100;
    const int *a = &num1;
    arrayInsert(array, 1, a);
    int num2 = 200;
    const int *b = &num2;
    arrayInsert(array, 1, a);
    dumpArr(array);
    return 0;
}
