#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int solve(TreeNode<int>*root, long long int&ans){
    if(root==NULL) return 0;

    long long int leftSum=solve(root->left,ans);
    long long int rightSum=solve(root->right,ans);
    ans=max(ans,leftSum+rightSum+root->val);

    return root->val + max(leftSum,rightSum);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL || (root->left==NULL || root->right==NULL)) return -1;
    long long int ans=0;
    solve(root,ans);
    return ans;
}