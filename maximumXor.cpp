#include <bits/stdc++.h>

class TrieNode {
public:
  TrieNode *bits[2];
  TrieNode() { bits[0] = bits[1] = NULL; }
};

class Trie {
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }
  void insert(int num) {
    TrieNode *node = root;
    for (int i = 31; i >= 0; i--) {
      int bit = (num >> i) & 1;
      if (node->bits[bit] == NULL)
        node->bits[bit] = new TrieNode();
      node = node->bits[bit];
    }
  }
  int getMaxXor(int num) {
    TrieNode *node = root;
    int ans = 0;

    for (int i = 31; i >= 0; i--) {
      int bit = (num >> i) & 1;
      int oppBit = !bit;
      if (node->bits[oppBit] == NULL)
        node = node->bits[bit];
      else {
        node = node->bits[oppBit];
        ans = ans | (1 << i);
      }
    }
    return ans;
  }
};

int maximumXor(vector<int> A) {
  Trie *root = new Trie();
  for (auto num : A) {
    root->insert(num);
  }

  int ans = INT_MIN;
  for (auto num : A) {
    ans = max(ans, root->getMaxXor(num));
  }

  return ans;
}