// ********************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
	// Write your code here
    if(root==NULL) return NULL;
    if(root->data==p->data || root->data==q->data) return root;

    if(p->data < root->data && q->data < root->data) return LCAinaBST(root->left, p, q);
    else if(p->data > root->data && q->data > root->data) return LCAinaBST(root->right,p,q);
    else return root;
}
