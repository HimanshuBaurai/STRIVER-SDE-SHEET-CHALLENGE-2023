#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    // //brute force, O(N2)
    // int cnt=0;
    // int n=arr.size();
    // for(int i=0;i<n;i++){
    //     int xr=0;
    //     for(int j=i;j<n;j++){
    //         xr=xr^arr[j];
    //         if(xr==x) cnt++;
    //     }
    // }
    // return cnt;

    //optimal O(N)
    unordered_map<int,int>mpp;
    int n=arr.size();
    int cnt=0;
    int xr=0;
    for(int i=0;i<n;i++){
        xr=xr^arr[i];
        if(xr==x) cnt++;
        if(mpp.count(x^xr)){
            cnt+=mpp[x^xr];
        }
        mpp[xr]++;
    }
    return cnt;
}