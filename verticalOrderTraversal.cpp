#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    map<int,map<int,vector<int>>>mpp;

    queue<pair<pair<int,int>,TreeNode<int>*>>q;
    q.push({{0,0},root});
    while(!q.empty()){
        int size=q.size();
        while(size--){
            auto p=q.front(); q.pop();
            int x=p.first.first;
            int y=p.first.second;
            TreeNode<int>* node=p.second;
            mpp[x][y].push_back(node->data);

            if(node->left) q.push({{x-1,y+1},node->left});
            if(node->right) q.push({{x+1,y+1},node->right});
        }
    }

    vector<int>ans;
    for(auto it: mpp){
        for(auto mpp2: it.second){ 
            ans.insert(ans.end(),mpp2.second.begin(),mpp2.second.end());
        }
    }
    return ans;
}