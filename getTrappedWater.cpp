#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    vector<long>pre(n);
    vector<long>succ(n);
    for(int i=0;i<n;i++){
        if(i==0) pre[0]=arr[0];
        else pre[i]=max(pre[i-1],arr[i]);

        if(n-1-i==n-1) succ[n-1-i]=arr[n-1-i];
        else succ[n-1-i]=max(succ[n-i],arr[n-1-i]);
    }

    long ans=0;
    for(int i=0;i<n;i++){
        ans+= min(pre[i],succ[i])<=arr[i] ? 0 : min(pre[i],succ[i])-arr[i];
    }
    return ans;
}