/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
  if (head == NULL || k == 0 || head->next==NULL)
    return head;

  Node *temp = head;
  int len = 1;
  while (temp->next) {
    temp = temp->next;
    len++;
  }
  temp->next = head;//make ll circular
  
  k=k%len;
  int steps=len-k;
  while (steps--) { temp = temp->next; }
  head = temp->next;
  temp->next = NULL;
  return head;
}