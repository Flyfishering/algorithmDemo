#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdlib.h>
#include <stdio.h>
typedef char ElemType;
typedef struct LNode 
{
	ElemType data;
	struct LNode*next;
}LinkList;
// 创建链表，链表节点 从 链表头部插入 
void CreateListHead(LinkList *&L,ElemType a[],int n);
// 创建链表，链表节点 从 链表尾部插入
void CreateListTail(LinkList *&L,ElemType a[],int n);
// 初始化 链表
void InitList(LinkList *&L);
// 释放链表
void DestroyList(LinkList *&L);
// 是否是空链表
bool ListEmpty(LinkList *L);
// 链表长度 
int ListLength(LinkList *L);
// 打印链表
void ShowList(LinkList *L);
// 查找链表中 第 i 个节点值
bool GetListElem(LinkList *L,int i,ElemType &e);
// 在位置 i 处，插入新节点
int LocateElem(LinkList*L,ElemType e);
// 在位置 i 处，插入新节点
bool ListInsert(LinkList *&L,int i,ElemType e);
// 删除 链表中 第 i 个节点
bool ListDelete(LinkList *&L,int i,ElemType &e);
#endif
