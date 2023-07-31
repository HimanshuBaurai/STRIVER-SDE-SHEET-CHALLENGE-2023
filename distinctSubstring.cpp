#include <bits/stdc++.h>
class TrieNode {
public:
  TrieNode *child[26]; 

  TrieNode() {
    for (int i = 0; i < 26; i++) {
      this->child[i] = NULL;
    } 
  }

  bool containsKey(char ch){
      return child[ch-'a']!=NULL;
  }
  void put(char ch, TrieNode*node){
      child[ch-'a']= node;
  }
  TrieNode* get(char ch){
      return child[ch-'a'];
  }
};  

int distinctSubstring(string &word) {
    TrieNode* root= new TrieNode();
    int cnt=0;
    int n=word.length();

    for(int i=0;i<n;i++){
        TrieNode* node=root;
        for(int j=i;j<n;j++){
            if(node->containsKey(word[j])==false){
                node->put(word[j], new TrieNode());
                cnt++;
            }
            node=node->get(word[j]);
        }
    }

    return cnt;
}
