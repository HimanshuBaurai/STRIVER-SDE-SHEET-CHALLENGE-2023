#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int,int>mpp;
    for(auto& num: arr){
        mpp[num]++;
    }
    priority_queue<pair<int,int>>pq;
    for(auto it: mpp){
        pq.push({it.second,it.first});
    }

    vector<int>ans;
    for(int i=0;i<k;i++){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    
    sort(ans.begin(),ans.end());
    return ans;
}