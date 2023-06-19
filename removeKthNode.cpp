/*
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
*/

int length(Node*head){
    int len=0;
    Node*curr=head;
    while(curr){
        len++;
        curr=curr->next;
    }
    return len;
}
Node* removeKthNode(Node* head, int K)
{
    // //brute force O(2*N)
    // int len=length(head);
    // if(len==K){
    //     //delete head
    //     if(head->next==NULL) return NULL;
    //     else return head->next;
    // }

    // int reqPos=len-K-1;//0 based indexing,node prev to req node
    // int pos=0;

    // Node*curr=head;
    // while(pos!=reqPos){
    //     curr=curr->next;
    //     pos++;
    // }
    // curr->next=(curr->next)->next;
    // return head;


    //optimal O(N)
    Node*dummy= new Node(0);
    dummy->next=head;

    Node*fast=dummy, *slow=dummy;
    for(int i=1;i<=K;i++){
        fast=fast->next;
    }
    while(fast->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=(slow->next)->next;
    return dummy->next;

}
