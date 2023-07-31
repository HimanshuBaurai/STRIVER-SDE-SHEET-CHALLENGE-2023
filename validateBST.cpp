#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool validateBST(BinaryTreeNode<int> *root) {
   if(root==NULL) return true;

   return (root->left ? root->data>=root->left->data : true)
            && (root->right ? root->data<=root->right->data : true)
            && validateBST(root->left) && validateBST(root->right);
}