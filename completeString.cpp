#include <bits/stdc++.h> 

class TrieNode {
public:
  TrieNode *child[26];
//   int prefix;
  bool isEnd;
  TrieNode() {
    for (int i = 0; i < 26; i++) {
      this->child[i] = NULL;
    }
    // prefix = 0;
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
    //   node->prefix++;
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

//   bool startsWith(string prefix) {
//     TrieNode *node = root;
//     for (auto ch : prefix) {
//       if (node->child[ch - 'a'] == NULL)
//         return false;
//       node = node->child[ch - 'a'];
//     }
//     return node->prefix != 0;
//   }
};

string completeString(int n, vector<string> &a){
    Trie*root= new Trie();

    for(auto word :a){
        root->insert(word);
    }
    
    string ans="";
    for(auto word: a){
        string temp="";
        bool flag=true;
        for(auto ch: word){
            temp+=ch;
            if(root->search(temp)==false){ flag=false; break;}
        }
        if(flag){
            if(ans.length()==0 || ans.length()<word.length() || (word.length()==ans.length() && word<ans)) ans=word; 
        }
    }
    return ans.length()==0 ? "None" : ans;
}