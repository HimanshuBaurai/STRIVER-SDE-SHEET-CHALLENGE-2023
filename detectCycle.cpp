
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

bool detectCycle(Node *head)
{
	//single non cyclic node, or a null node
    if(head==NULL || head->next==NULL) return false;

    Node*fast=head, *slow=head;
    do{
        if(fast==NULL || fast->next==NULL) return false;//if it is cyclic how it can reach the end
        fast=(fast->next)->next;
        slow=slow->next;
    }while(fast!=slow);

    fast=head;
    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
    }
    
    if(fast!=NULL) return true;
    else return false;
}