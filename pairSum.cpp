#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   //brute force -->O(N2)
   //optimal-->O(N) using map
   unordered_map<int,int>mpp;
   vector<vector<int>>res;
   for(auto num: arr){
      if(mpp.count(s-num)){
         int freq=mpp[s-num]; 

         vector<int>ans;
         ans.push_back(num);
         ans.push_back(s-num);
         sort(ans.begin(),ans.end());
         
         while(freq--){
            res.push_back(ans);
         }
      }
      mpp[num]++;
   }
   sort(res.begin(),res.end());
   return res;
}