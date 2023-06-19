/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/
#include<bits/stdc++.h>
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    // Node*p1=firstHead; Node*p2=secondHead;
    // while(p1 && p2 && p1!=p2){
    //     p1=p1->next;
    //     p2=p2->next;
    //     if(p1==p2) return p1;
    //     if(p1==NULL) p1=secondHead;
    //     if(p2==NULL) p2=firstHead;
        
    // }
    // return p1; 


    //using set
    Node *f=firstHead;
    Node *s=secondHead;
    unordered_set<Node *>st;
     while(f)
     {
        st.insert(f);
        f=f->next;
    }

     while(s) { 
         if(st.find(s)!=st.end()) { return s; }
         s=s->next;
    }
    return NULL;
}