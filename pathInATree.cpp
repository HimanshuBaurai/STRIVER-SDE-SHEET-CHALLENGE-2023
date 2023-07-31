#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/

void path(TreeNode<int>*root, int x, vector<int>&ans, vector<int>&vec){
   if(root==NULL) return;
   
   vec.push_back(root->data);
   if(root->data==x){
	   ans=vec;
	   return;
   }
   path(root->left,x,ans,vec);
   path(root->right,x,ans,vec);
   vec.pop_back();
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
	vector<int>ans;
	vector<int>vec;
    path(root,x,ans,vec);
	return ans;
}
