#include <bits/stdc++.h> 

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // O(NlogN) -->TimeComplexity
    sort(intervals.begin(),intervals.end());

    vector<vector<int>>res;
    res.push_back(intervals[0]);
    int prevStart=intervals[0][0], prevEnd=intervals[0][1];

    int n=intervals.size();
    for(int i=1;i<n;i++){
        int currStart=intervals[i][0], currEnd=intervals[i][1];
        if(currStart<=prevEnd){
            res.pop_back();
            prevStart=min(prevStart,currStart);
            prevEnd=max(prevEnd,currEnd);
            res.push_back({prevStart,prevEnd});
        }
        else{
            res.push_back(intervals[i]);
            prevStart=currStart;
            prevEnd=currEnd;
        }
    }
    return res;
}
