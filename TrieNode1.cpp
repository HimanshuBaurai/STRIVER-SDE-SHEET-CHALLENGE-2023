/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class TrieNode {
public:
  TrieNode *child[26];
  int prefix;
  bool isEnd;
  TrieNode() {
    for (int i = 0; i < 26; i++) {
      this->child[i] = NULL;
    }
    prefix = 0;
    isEnd = false;
  }
};

class Trie {
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode *node = root;
    for (auto ch : word) {
      if (node->child[ch - 'a'] == NULL)
        node->child[ch - 'a'] = new TrieNode();
      node = node->child[ch - 'a'];
      node->prefix++;
    }
    node->isEnd = true;
  }

  bool search(string word) {
    TrieNode *node = root;
    for (auto ch : word) {
      if (node->child[ch - 'a'] == NULL)
        return false;
      node = node->child[ch - 'a'];
    }
    return node->isEnd;
  }

  bool startsWith(string prefix) {
    TrieNode *node = root;
    for (auto ch : prefix) {
      if (node->child[ch - 'a'] == NULL)
        return false;
      node = node->child[ch - 'a'];
    }
    return node->prefix != 0;
  }
};