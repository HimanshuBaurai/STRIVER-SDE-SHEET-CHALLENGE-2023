#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    map<int,int>mpp;
    vector<int>ans;
    if(root==NULL) return ans;
    
    queue<pair<int,TreeNode<int>*>>q;
    q.push({0,root});
    while(!q.empty()){
        int size=q.size();
        while(size--){
            auto p=q.front(); q.pop();
            if(mpp.count(p.first)==0) mpp[p.first]=p.second->val;

            if(p.second->left) q.push({p.first-1,p.second->left});
            if(p.second->right) q.push({p.first+1,p.second->right});
        }
    }
    for (auto it : mpp) {
      ans.push_back(it.second);
    }
    return ans;
}