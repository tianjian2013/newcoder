#include <iostream>
using namespace std;
class ListNode {
public:	
int val;
ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
       ListNode* p=pHead;
       ListNode* q=pHead->next;
       while(p!=q&&p!=q->next){
           p=p->next;
           q=q->next->next;
       }
       ListNode* inloop=p;
       p=pHead;
       int num1=0;
       while(p!=inloop){
           p=p->next;
           num1++;
       }
       int num2=1;
       q=inloop->next;
       while(q!=inloop){
           q=q->next;
           num2++;
       }
       p=pHead;
       q=inloop;
       int k=num1-num2;
       if(k>0){
           for(int i=0;i<k;i++)
               p=p->next;
       }
       if(k<0){
           for(int i=0;i<-k;i++)
               q=q->next;
       }
        while(p!=q)
        {
            p=p->next;
            q=q->next;
        }
        return p;
       
	}
};

int main()
{
ListNode a0(0);
ListNode a1(1);
ListNode a2(2);
ListNode a3(3);
ListNode a4(4);
ListNode a5(5);
ListNode a6(6);
ListNode a7(7);
ListNode a8(8);
ListNode a9(9);

a0.next=&a1;
a1.next=&a2;
a2.next=&a3;
a3.next=&a4;
a4.next=&a5;
a5.next=&a6;
a6.next=&a7;
a7.next=&a8;
a8.next=&a9;
a9.next=&a9;


Solution sl;
ListNode *ret=sl.EntryNodeOfLoop(&a0);
cout<< ret->val<<endl;
return 0;
}
