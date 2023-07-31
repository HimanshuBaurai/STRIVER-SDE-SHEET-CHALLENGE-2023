#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool leafNode(TreeNode<int>*root){
    return root!=NULL && (root->left==NULL && root->right==NULL);
}
void leftBoundary(TreeNode<int>*root, vector<int>&ans){
    while(root){
        if(!leafNode(root))ans.push_back(root->data);
        if(root->left) root=root->left;
        else root=root->right;
    }
}
void leafBoundary(TreeNode<int>*root,vector<int>&ans){
    if(root==NULL) return;

    leafBoundary(root->left,ans);
    if(leafNode(root)) ans.push_back(root->data);
    leafBoundary(root->right,ans);
}
void rightBoundary(TreeNode<int>*root, vector<int>&ans){
    vector<int>temp;
    while(root){
        if(!leafNode(root))temp.push_back(root->data);
        if(root->right) root=root->right;
        else root=root->left;
    }

    int n=temp.size();
    for(int i=n-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>ans;
    if(root==NULL) return ans;

    ans.push_back(root->data);
    if(leafNode(root)) return ans;
    //push left boundary
    leftBoundary(root->left,ans);
    //push leaf nodes
    leafBoundary(root,ans);
    // push right boundary
    rightBoundary(root->right,ans);

    return ans;
}