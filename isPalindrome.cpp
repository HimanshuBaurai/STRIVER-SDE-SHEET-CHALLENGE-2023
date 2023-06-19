#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
int length(LinkedListNode<int> *head){
    int len=0;
    LinkedListNode<int> *curr=head;
    while(curr){
        len++;
        curr=curr->next;
    }
    return len;
}

LinkedListNode<int> *reverse(LinkedListNode<int> *head) 
{
    if(head==NULL || head->next==NULL) return head;

    LinkedListNode<int>*prev=NULL,*curr=head,*next=NULL;
    while(curr){
        next=curr->next;

        curr->next=prev;

        prev=curr;
        curr=next;
    }

    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    //brute force, save in a vector and return ans;

    //optimal--> find mid, reverse half, and then use 2pointers and move simlutaneously to check if its a palindrome or not
    if(head==NULL || head->next==NULL) return true;
    
    int len=length(head);
    int mid=len/2;
    LinkedListNode<int>*curr=head;
    for(int i=1;i<mid;i++){
        curr=curr->next;
    }
    LinkedListNode<int>*p2= len%2==0 ? reverse(curr->next) : reverse(curr->next->next);
    curr->next=NULL;
    LinkedListNode<int>*p1=head;
    while(p1 && p2){
        if(p1->data != p2->data) return false;
        p1=p1->next;
        p2=p2->next;
    }
    return true;
}