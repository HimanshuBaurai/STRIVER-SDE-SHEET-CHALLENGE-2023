#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
// TreeNode<int>*search(TreeNode<int>*root, int x){
//     if(root==NULL) return NULL;
//     if(root->data==x) return root;
//     else if(x < root->data) return search(root->left,x);
//     else search(root->right,x);
// }
int floorInBST(TreeNode<int> * root, int x)
{
    // Write your code here.
    TreeNode<int>*curr=root;
    int ans;
    while(curr){
        if(x==curr->val) return x;
        else if(x<curr->val) curr=curr->left;
        else{
            ans=curr->val;
            curr=curr->right;
        }
    }
    return ans;
}