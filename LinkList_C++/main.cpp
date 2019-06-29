#include"LinkList.h"
//char array1[]= {'a','b','c','b','a'};
char array1[]= {'1','2','3','4','5'};
bool isPalindrome(LinkList * list,int length);
int main()
{
	LinkList * list;

	int length = sizeof(array1)/sizeof(array1[0]);
	InitList(list);
    
//    CreateListTail(list,array1,length);
    //  a  b  c  b  a 
    //  1  2  3  4  5
//    ShowList(list);
    CreateListHead(list, array1, length);
    //a  b  c  b  a 
    // 5  4  3  2  1 
    ShowList(list);
    if(isPalindrome(list,length))
		printf("isPalindrome\n");
	else
		printf("isNotPalindrome\n");
	return 0;
}
bool isPalindrome(LinkList * list,int length)
{
	int i;
	char buff1[length],buff2[length];
	ElemType e;
	for(i=1; i<=length; i++) 
	{
		GetListElem(list,i,e);//������ȡ����Ԫ�ز����������� 
		buff1[i-1]=e;//�������� 
		buff2[length-i]=e;//�������� 
	}
	i=0;
	while(i<=length) {
		if(buff1[i]==buff2[i])//�Ƚ� 
		{
			i++; 
		} 
		else 
		{
			return false;
		}
	}
	return true;
}
