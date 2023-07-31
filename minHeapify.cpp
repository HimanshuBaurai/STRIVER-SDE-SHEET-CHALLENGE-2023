#include <bits/stdc++.h>

void minHeapify(int i, vector<int> &myHeap) {
  int n = myHeap.size();
  int leftChild = 2 * i + 1;
  int rightChild = 2 * i + 2;
  int mini = i;

  if (leftChild < n && myHeap[leftChild] < myHeap[mini])
    mini = leftChild;
  if (rightChild < n && myHeap[rightChild] < myHeap[mini])
    mini = rightChild;
  if (mini == i)
    return; // already heapified

  swap(myHeap[i], myHeap[mini]);
  minHeapify(mini, myHeap);
}
void insert(vector<int>&myHeap,int x){
    myHeap.push_back(x);
    
    int idx=myHeap.size()-1;
    int parentIdx=(idx-1)/2;
    while(myHeap[parentIdx]>myHeap[idx]){
        minHeapify(parentIdx,myHeap);
        idx=parentIdx;
        parentIdx=(parentIdx-1)/2;
    }
}
int removeHead(vector<int> &myHeap) {
  int ans = myHeap[0];
  swap(myHeap[0], myHeap[myHeap.size() - 1]);
  myHeap.pop_back();
  minHeapify(0, myHeap);
  return ans;
}
vector<int> minHeap(int n, vector<vector<int>> &q) {
  vector<int> myHeap;
  vector<int> ans;
  for (int i = 0; i < q.size(); i++) {
    if (q[i][0] == 0) {
      insert(myHeap, q[i][1]);
    } else {
      ans.push_back(removeHead(myHeap));
    }
  }
  return ans;
}
