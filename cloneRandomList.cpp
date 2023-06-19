#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{

    LinkedListNode<int>*itr=head, *front=head;
    while(itr){
        front=itr->next;
        LinkedListNode<int>* newNode= new LinkedListNode<int>(itr->data);
        itr->next=newNode;
        newNode->next=front;
        itr=front;
    }

    itr=head;
    while(itr){
        if(itr->next){
            (itr->next)->random=(itr->random)!=NULL ? itr->random->next : NULL;
        }
        itr=(itr->next)->next;
    }

    itr=head;
    LinkedListNode<int>*dummy= new LinkedListNode<int>(0);
    LinkedListNode<int>*copyHead=dummy;
    while(itr){
        front=itr->next->next;
        dummy->next=itr->next;
        itr->next=front;
        dummy=dummy->next;
        itr=itr->next;
    }
    return copyHead->next;
}


// LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
// {
//     // Write your code here.
//     LinkedListNode<int>*curr = head;
//     unordered_map<LinkedListNode<int>*, LinkedListNode<int>*>mp;
//     while(curr!=NULL){
//         LinkedListNode<int>*temp = new LinkedListNode<int>(curr->data);
//         mp[curr]=temp;
//         curr=curr->next;
//     }
//     curr=head;
//     while(curr!=NULL){
//         LinkedListNode<int>*temp = mp[curr];
//         temp->next = mp[curr->next];
//         temp->random = mp[curr->random];
//         curr=curr->next;
//     }
//     return mp[head];
// }