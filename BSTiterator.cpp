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

class BSTiterator {
public:
  stack<TreeNode<int> *> stk;
  BSTiterator(TreeNode<int> *root) {
    while (root) {
      stk.push(root);
      root = root->left;
    }
  }

  int next() {
    TreeNode<int> *top = stk.top();
    stk.pop();

    TreeNode<int> *temp = top->right;

    while (temp) {
      stk.push(temp);
      temp = temp->left;
    }

    return top->data;
  }

  bool hasNext() {
    // write your code here
    return !stk.empty();
  }
};

/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/