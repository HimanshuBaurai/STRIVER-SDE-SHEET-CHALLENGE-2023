#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int> *LCA(TreeNode<int>*root,int x, int y){
    if(root==NULL || root->data==x || root->data==y) return root;

    TreeNode<int>*left=LCA(root->left,x,y);
    TreeNode<int>*right=LCA(root->right,x,y);

    if(left&&right) return root;
    else if(left==NULL && right) return right;
    else if(left && right==NULL) return left;
    else return NULL;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	return LCA(root,x,y)->data;
}