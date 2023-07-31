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
#include <bits/stdc++.h>

string serializeTree(TreeNode<int> *root) {
  string ans = "";
  // do level order traversal, NULL denoted by #, and number saparated by ,
  if (root == NULL)
    return ans;
  queue<TreeNode<int> *> q;
  q.push(root);
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      TreeNode<int> *node = q.front();
      q.pop();
      if (node == NULL)
        ans += "#,";
      else {
        ans += (to_string(node->data) + ",");
        q.push(node->left);
        q.push(node->right);
      }
    }
  }
  return ans;
}

TreeNode<int> *deserializeTree(string &data) {
  if (data.size() == 0)
    return NULL;
  stringstream s(data);
  string str;
  getline(s, str, ',');
  TreeNode<int> *root = new TreeNode<int>(stoi(str));
  queue<TreeNode<int> *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode<int> *node = q.front();
    q.pop();

    getline(s, str, ',');
    if (str == "#") {
      node->left = NULL;
    } else {
      TreeNode<int> *leftnode = new TreeNode<int>(stoi(str));
      node->left = leftnode;
      q.push(leftnode);
    }
    getline(s, str, ',');
    if (str == "#") {
      node->right = NULL;
    } else {
      TreeNode<int> *rightnode = new TreeNode<int>(stoi(str));
      node->right = rightnode;
      q.push(rightnode);
    }
  }

  return root;
}
