#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  unordered_map<int,int>mpp;
  int sum=0,len=0,n=arr.size();
  mpp[0]=-1;//keep this in mind
  for(int i=0;i<n;i++){
    sum+=arr[i];
    if(mpp.count(sum)){
      len=max(len,i-mpp[sum]);
    }
    else mpp[sum]=i;
  }
  return len;
}