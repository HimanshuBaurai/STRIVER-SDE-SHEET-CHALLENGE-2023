/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node*dummy= new Node(0);
    Node*curr=dummy;

    int carry=0;
    while(num1 || num2 || carry){
        int sum=0;

        sum+=carry;
        if(num1){
            sum+=num1->data;
            num1=num1->next;
        }
        if(num2){
            sum+=num2->data;
            num2=num2->next;
        }

        Node* newNode = new Node(sum%10);
        curr->next=newNode;
        curr=curr->next;
        carry=sum/10;
    }
    if(carry){
        Node* newNode= new Node(carry);
        curr->next=newNode;
    }
    return dummy->next;
}
