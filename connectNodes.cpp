#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    BinaryTreeNode<int>*prev=NULL;
    while(!q.empty()){
        int size=q.size();
        
        prev=q.front();
        if(prev->left) q.push(prev->left);
        if(prev->right) q.push(prev->right);
        q.pop();

        for(int i=0;i<size-1;i++){
            prev->next=q.front();
            prev=q.front();

            if(prev->left) q.push(prev->left);
            if(prev->right) q.push(prev->right);

            q.pop();
        }
        prev->next=NULL;
    }
}