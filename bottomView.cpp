#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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
 
vector<int> bottomView(BinaryTreeNode<int> * root){

    map<int,int>mpp;
    vector<int>ans;
    if(root==NULL) return ans;
    
    queue<pair<int,BinaryTreeNode<int>*>>q;
    q.push({0,root});
    while(!q.empty()){
        int size=q.size();
        while(size--){
            auto p=q.front(); q.pop();
            mpp[p.first]=p.second->data;

            if(p.second->left) q.push({p.first-1,p.second->left});
            if(p.second->right) q.push({p.first+1,p.second->right});
        }
    }
    for(auto it: mpp){
        ans.push_back(it.second);
    }
    return ans;
    
}
