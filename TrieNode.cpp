#include <bits/stdc++.h>
class TrieNode {
public:
  TrieNode *child[26];
  int countEnd;
  int prefix;

  TrieNode() {
    for (int i = 0; i < 26; i++) {
      this->child[i] = NULL;
    }
    countEnd = 0;
    prefix = 0;
  }
};

class Trie {
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }

  void insert(string &word) {
    TrieNode *node = root;
    for (auto &ch : word) {
      if (node->child[ch - 'a'] == NULL)
        node->child[ch - 'a'] = new TrieNode();
      node = node->child[ch - 'a'];

      node->prefix++;
    }
    node->countEnd++;
  }

  int countWordsEqualTo(string &word) {
    TrieNode *node = root;
    for (auto &ch : word) {
      if (node->child[ch - 'a'] == NULL)
        return 0;
      node = node->child[ch - 'a'];
    }
    return node->countEnd;
  }

  int countWordsStartingWith(string &word) {
    TrieNode *node = root;
    for (auto &ch : word) {
      if (node->child[ch - 'a'] == NULL)
        return 0;
      node = node->child[ch - 'a'];
    }
    return node->prefix;
  }

  void erase(string &word) {
    TrieNode *node = root;
    for (auto &ch : word) {
      if (node->child[ch - 'a'] == NULL)
        return;
      node = node->child[ch - 'a'];

      node->prefix--;
    }
    node->countEnd--;
  }
};
