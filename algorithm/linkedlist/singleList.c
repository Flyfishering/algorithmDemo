//
//  singleList.c
//  algorithm
//
//  Created by 斌 on 2019/1/12.
//  Copyright © 2019 wangbinbin. All rights reserved.
//

#include "singleList.h"
#include <string.h>
// 创建链表
linkedList * listCreate()
{
    linkedList *list = NULL;
    list = malloc(sizeof(*list));
    printf("sizeof(*list) = %lu\n",sizeof(*list));
    if (NULL == list)
    {
        return NULL;
    }
    
    list->dup = NULL;
    list->free = NULL;
    list->match = NULL;
    
    list->head = NULL;
    list->len = 0;
    
    return list;
}

// 释放
void listRelease(linkedList *list)
{
    if (NULL == list)
    {
        return;
    }
    
    listEmpty(list);
    
    free(list);
    list = NULL;
}

void listEmpty(linkedList *list)
{
    if (NULL == list)
    {
        return;
    }
    
    while (NULL != list->head)
    {
        listNode *pNode = list->head;
        list->head = pNode->next;
        if (NULL != list->free)
        {
            list->free(pNode->value);
        }
        else
        {
            free(pNode->value);
        }
        
        pNode->next = NULL;
        free(pNode);
        pNode = NULL;
    }
}

linkedList * listAddNodeHead(linkedList *list, void * value)
{
    // 参数合法性判断
    if (NULL == list || NULL == value)
    {
        return list;
    }
    // 创建节点
    listNode *node = NULL;
    node = malloc(sizeof(*node));
    if (NULL == node)
    {
        return list;
    }
    
    node->value = value;
    node->next = list->head;
    list->head = node;
    
    // list 属性对应更改
    ++list->len;
    return list;
}

linkedList * listAddNodeTail(linkedList *list, void *value)
{
    // 参数合法性验证
    if (NULL == list || NULL == value)
    {
        return list;
    }
    // 创建节点
    listNode *node = NULL;
    node = malloc(sizeof(*node));
    if (NULL == node)
    {
        return list;
    }
    
    node->value = value;
    node->next = NULL;
    // 如果链表没有 head 指向，将该节点作为 head 指向
    if (NULL == list->head
        && list->len == 0)
    {
        list->head = node;
    }
    else
    {
        listNode *tail = list->head;
        listNode *pre = list->head;
        // 循环遍历到最后一个节点
        while (NULL != tail)
        {
            pre = tail;
            tail = tail->next;
        }
        
        pre->next = node;
    }
    
    ++list->len;
    return list;
}

linkedList * listInsertNode(linkedList *list, listNode *old_node, void *value, bool after)
{
    // 参数合法性验证
    if (NULL == list || NULL == old_node)
    {
        return list;
    }
    // 创建新节点
    listNode *pNode = NULL;
    pNode = malloc(sizeof(*pNode));
    if (NULL == pNode)
    {
        return list;
    }
    pNode->value = value;
    // 插入到 参数节点后面
    if (after)
    {
        pNode->next = old_node->next;
        old_node->next = pNode;
    }
    else
    {
        // 插入到 参数苏节点前面
        listNode *pre = list->head;
        while (pre->next != old_node)
        {
            pre = pre->next;
        }
        
        if (NULL != pre)
        {
            pre->next = pNode;
            pNode->next = old_node;
        }
    }
    
    ++list->len;
    return list;
}

// 没设置释放函数时不做释放处理
void listDelNode(linkedList *list, listNode *node)
{
    if (NULL == list || NULL == node)
    {
        return;
    }
    
    listNode *pre = list->head;
    listNode *cur = list->head;
    // 找到该节点
    while (NULL != cur && cur != node)
    {
        pre = cur;
        cur = cur->next;
    }
    
    // 不在该链表中
    if (NULL == pre)
    {
        return;
    }
    // 将该节点在 链表中删除
    pre->next = node->next;
    node->next = NULL;
    --list->len;
    // 当释放函数已经存在时
    if (NULL != list->free)
    {
        list->free(node->value);
        free(node);
        node = NULL;
    }
}
// 根据值 查找对应节点
listNode * listSearchKey(linkedList *list, void *key)
{
    if (NULL == list)
    {
        return NULL;
    }
    
    listNode *node = list->head;
    // 循环查找该节点
    while (NULL != node)
    {
        if (NULL != list->match)
        {
            if (list->match(key, node->value) == 0)
            {
                return node;
            }
        }
        else
        {
            if (key == node->value)
            {
                return node;
            }
        }
        
        node = node->next;
    }
    
    return NULL;
}
// 根据下标查找该节点
listNode * listIndex(linkedList *list, long index)
{
    if (NULL == list)
    {
        return NULL;
    }
    
    if (index <= 0
        || index > list->len)
    {
        return NULL;
    }
    
    listNode *pNode = list->head;
    for (long i = 0; i < index; ++i)
    {
        pNode = pNode->next;
    }
    
    return pNode;
}
/// 链表翻转
linkedList* listRewind(linkedList *list)
{
    if (NULL == list)
    {
        return NULL;
    }
    
    listNode *head = list->head;
    listNode *pre = NULL;
    listNode *next = NULL;
    while (NULL != head)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    
    list->head = pre;
    return list;
}
// 链表长度
size_t listLength(linkedList *list)
{
    if (NULL == list)
    {
        return 0;
    }
    
    return list->len;
}

void printfSingleList(linkedList *list){
    if(NULL == list)
    {
        return ;
    }
    listNode *node = list->head;
    while (NULL != node) {
        int *a = (int*)(node->value);
        int temp = *a;
        printf("%d \t",*a);
        node = node->next;
    }
    printf("\n");
}
void testLinkedList()
{
    linkedList *list = listCreate();
    int a = 4;
    int *p = &a;
    list = listAddNodeHead(list,p);
    
    int b = 5;
    p = &b;
    list = listAddNodeTail(list,p);
    
    int c = 6;
    p = &c;
    list = listAddNodeTail(list,p);
    
//    listNode *node = listIndex(list,1);
//    a = 10;
//    p = &a;
//    list = listInsertNode(list,node,p,true);
//    
//    
//    node = listIndex(list,1);
//    a = 8;
//    p = &a;
//    list = listInsertNode(list,node,p,true);
//    
//    
//    node = listIndex(list,1);
//    a = 7;
//    p = &a;
//    list = listInsertNode(list,node,p,true);
    
//    int num = 0;
//    while(num < 10){
//        a = num;
//        p = &a;
//        list = listInsertNode(list,node,p,true);
//        num++;
//    }
    
//    a = 5;
//    p = &a;
//    node = listSearchKey(list,p);
//    int *aa = node->value;
//    int temp = *aa;
//    printf("%d",*aa);
    
    printfSingleList(list);
}
