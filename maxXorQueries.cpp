#include<bits/stdc++.h>

class TrieNode {
public:
  TrieNode *bits[2];
  TrieNode() {
    for (int i = 0; i < 2; i++) {
      this->bits[i] = NULL;
    }
  }
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
  int getMax(int num) {
    int maxNum = 0;
    TrieNode *node = root;
    for (int i = 31; i >= 0; i--) {
      int bit = (num >> i) & 1;
      int opBit = 1 - bit;
      if (node->bits[opBit] == NULL)
        node = node->bits[bit];
      else {
        maxNum = maxNum | (1 << i);
        node = node->bits[opBit];
      }
    }
    return maxNum;
  }
  ~Trie() { delete root; }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries) {
  sort(arr.begin(),arr.end());
  vector<pair<int,pair<int,int>>>oQ;

  int i=0;
  for(auto q:queries){
	  int xi=q[0];
	  int ai=q[1];
	  oQ.push_back({ai,{xi,i++}});
  }
  sort(oQ.begin(),oQ.end());

  Trie*root= new Trie();
  int n=arr.size();
  int ind=0;
  vector<int>ans(oQ.size(),0);
  
  for(auto q: oQ){
	  int xi=q.second.first;
	  int qIndex=q.second.second;
	  int ai=q.first;

	  while(ind<n && arr[ind]<=ai){
		  root->insert(arr[ind++]);
	  }
	  if(ind==0) ans[qIndex]=-1;
	  else ans[qIndex]=root->getMax(xi);
  }

  return ans; 
}