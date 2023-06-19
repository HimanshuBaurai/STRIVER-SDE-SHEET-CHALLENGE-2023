/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node*merge(Node*h1, Node*h2){
	Node*dummy= new Node(0);
	Node*temp=dummy;

	while(h1 && h2){
		if(h1->data < h2->data){
			temp->child=h1;
			temp=temp->child;
			h1=h1->child;
		}
		else{
			temp->child=h2;
			temp=temp->child;
			h2=h2->child;
		}
	}
	if(h1) temp->child=h1;
	else temp->child=h2;

	return dummy->child;
}
Node* flattenLinkedList(Node* head) 
{
	if(head==NULL || head->next==NULL) return head;//single node

	Node* L2=flattenLinkedList(head->next);
	head->next=NULL;
	head=merge(head,L2);
	
	return head;
}
