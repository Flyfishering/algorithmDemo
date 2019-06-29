//
//  ListDemo.h
//  ListDemo01
//
//  Created by 斌 on 2019/6/26.
//  Copyright © 2019 wangbinbin. All rights reserved.
//

#ifndef ListDemo_h
#define ListDemo_h

#include <stdio.h>



typedef struct DlistNode          //双向链表中每一个节点
{                      
    struct DlistNode *prev;   //节点前项指针
    struct DlistNode *next;   //节点后项指针
    int    data;              //数据
}stDlistNode;

typedef struct Dlisthead          //定义链表总体
{
    int size;                 //链表长度
    stDlistNode *head;        //头指针
    stDlistNode *tail;        //尾部指针
}stDlistHead;

int test(void);
#endif /* ListDemo_h */
