#include "LinkList.h"

// 创建链表，链表节点 从 链表头部插入 
// 数组 array1[]= {'1','2','3','4','5'}; 
// 插入后：LinkList: 5->4->3->2->1
void CreateListHead(LinkList *&L,ElemType a[],int n)
{
    int i;
    LinkList *s;
    L = (LinkList *)malloc(sizeof(LinkList));
    L->next = NULL;
    for(i = 0;i < n;i++)
    {
        s=(LinkList*)malloc(sizeof(LinkList));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
}

// 创建链表，链表节点 从 链表尾部插入
// 数组 array1[]= {'1','2','3','4','5'}; 
// 插入后：LinkList: 1->2->3->4->5
void CreateListTail(LinkList *&L,ElemType a[],int n)
{
    int i;
    LinkList * s,* r;
    L = (LinkList *)malloc(sizeof(LinkList));
    r = L;
    for(i = 0;i < n;i++)
    {
        s = (LinkList *)malloc(sizeof(LinkList));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL; 
}
// 初始化 链表
void InitList(LinkList *&L)
{
    L=(LinkList *)malloc(sizeof(LinkList));
    L->next = NULL;
}
// 释放链表
void DestroyList(LinkList *&L)
{
    LinkList * pre = L,*p = L->next;
    while(p!=NULL)
    {
        free(pre);
        pre = p;
        p = L->next;
    }
    free(pre);
}
// 是否是空链表
bool ListEmpty(LinkList *L)
{
    return(L->next==NULL); 
}
// 链表长度
int ListLength(LinkList *L)
{
    int n = 0;
    LinkList * p = L;
    while(p->next!=NULL)
    {
        n++;
        p=p->next;
    }
    return(n);
}
// 打印链表
void ShowList(LinkList *L)
{
    LinkList * p = L->next;
    while(p!=NULL)
    {
        printf(" %c ",p->data);
        p = p->next; 
    } 
    printf("\n");
}
// 查找链表中 第 i 个节点值
bool GetListElem(LinkList *L,int i,ElemType &e)
{
    int j = 0;
    LinkList *p = L;
    while(j<i&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        e=p->data;
        return true;
    }
}
// 查找 值 e 在链表中的位置
int LocateElem(LinkList*L,ElemType e)
{
    int i=1;
    LinkList *p = L->next;
    while(p!=NULL&&p->data!=e){
        p=p->next;
        i++;
    }
    if(p==NULL)
    {
        return(0);
    }
    else
        return(i);
}
// 在位置 i 处，插入新节点
bool ListInsert(LinkList *&L,int i,ElemType e)
{
    int j=0;
    LinkList *p =L,*s;
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
    {
        return false;
    }
    else
    {
        s= (LinkList*)malloc(sizeof(LinkList));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
}
// 删除 链表中 第 i 个节点
bool ListDelete(LinkList *&L,int i,ElemType &e)
{
    int j=0;
    LinkList * p =L,*q;
    // 找到 第 i-1 处的节点
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
     // 删除第 i 个节点   
        q=p->next;
        if(q==NULL)
            return false;
        e=q->data;
        p->next=q->next;
        free(q);
        return true;
    }
}

