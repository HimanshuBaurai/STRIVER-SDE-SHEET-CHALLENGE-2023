#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k) {
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      minHeap;
  int n = kArrays.size();
  for (int i = 0; i < n; i++) {
    minHeap.push({kArrays[i][0], {i, 0}});
  }
  vector<int>ans;
  while(!minHeap.empty()){
      auto p=minHeap.top();
      minHeap.pop();
      int num=p.first;
      int arrayInd=p.second.first;
      int index=p.second.second;

      ans.push_back(num);

      if(index+1<kArrays[arrayInd].size()) minHeap.push({kArrays[arrayInd][index+1],{arrayInd,index+1}});
  }
  return ans;
}
