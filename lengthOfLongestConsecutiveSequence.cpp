#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int>st(arr.begin(),arr.end());
    int len=0;
    for(auto num: arr){
        if(!st.count(num-1)){
            int currNum=num;
            int currStreak=1;
            while(st.count(currNum+1)){
                currStreak++;
                currNum++;
            }
            len=max(len,currStreak);
        }
    }
    return len;
}