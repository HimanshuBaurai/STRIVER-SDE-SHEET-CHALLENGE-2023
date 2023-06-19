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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
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