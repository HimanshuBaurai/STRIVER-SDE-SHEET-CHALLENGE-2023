#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==NULL) return second;
    else if(second==NULL) return first;

    Node<int>*dummy= new Node<int>(0);
    Node<int>*curr=dummy;

    while(first && second){
        if(first->data < second->data){
            curr->next=first;
            first=first->next;
        }
        else{
            curr->next=second;
            second=second->next;
        }
        curr=curr->next;
    }
    if(first) curr->next=first;
    else if(second) curr->next=second;

    return dummy->next;
}
