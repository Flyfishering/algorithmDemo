//
//  singleList.h
//  algorithm
//
//  Created by 斌 on 2019/1/12.
//  Copyright © 2019 wangbinbin. All rights reserved.
//

#ifndef singleList_h
#define singleList_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// 单链表
typedef struct listNode
{
    // 链表的 后继指针 指向下一个单链表
    struct listNode *next;
    //链表存储的值
    void *value;
}listNode;

// 链表的方法和头地址以及长度等
typedef struct linkedList
{
    // 单链表的头地址
    listNode *head;
    // 链表 长度
    size_t len;
    // 链表 单位长度
    size_t typesize;
    
    void(*dup)(void*, void*);
    // 匹配指针函数
    int(*match)(void*, void*);
    // 释放内存指针函数
    void(*free)(void*);
}linkedList;
// 链表的函数实现 宏定义
#define listSetDupMethod(l,m) ((l)->dup = (m))
#define listSetFreeMethod(l,m) ((l)->free = (m))
#define listSetMatchMethod(l,m) ((l)->match = (m))

#define listGetDupMethod(l) ((l)->dup)
#define listGetFree(l) ((l)->free)
#define listGetMatchMethod(l) ((l)->match)
// 链表的创建
linkedList *listCreate();
// 链表的释放
void listRelease(linkedList *list);
// 清空链表
void listEmpty(linkedList *list);
// 添加链表头地址指向
linkedList *listAddNodeHead(linkedList *list, void *value);
// 添加链表尾部地址指向
linkedList *listAddNodeTail(linkedList *list, void *value);
// 链表插入值
linkedList *listInsertNode(linkedList *list, listNode *old_node, void *value, bool after);
// 链表删除值
void listDelNode(linkedList *list, listNode *node);
// 链表查找值
listNode *listSearchKey(linkedList *list, void *key);
// 链表 查找对应下标的值
listNode *listIndex(linkedList *list, long index);
linkedList* listRewind(linkedList *list);
// 链表长度
size_t listLength(linkedList *list);
void testLinkedList();
#endif /* singleList_h */
