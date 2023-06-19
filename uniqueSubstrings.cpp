#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //sliding window-->O(N)
    int len=1;
    int n=input.length();
    unordered_map<char,int>mpp;
    int i=0,j=0;
    while(i<n && j<n){
        if(mpp.count(input[j])){
            //already exist there
            while(mpp.count(input[j])){
                mpp[input[i]]--;
                if(mpp[input[i]]==0) mpp.erase(input[i]);
                i++;
            }
        }
        else len=max(len,j-i+1);

        mpp[input[j]]++;
        j++;
    }
    return len;
}