#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    stack<int>stk;
    vector<int>leftSmall(n);
    for(int i=0;i<n;i++){
        while(!stk.empty() && a[stk.top()]>=a[i]) stk.pop();
        if(stk.empty()) leftSmall[i]=-1;
        else leftSmall[i]=stk.top();
        stk.push(i);
    }

    while(!stk.empty()) stk.pop();
    
    vector<int>rightSmall(n);
    for(int i=n-1;i>=0;i--){
        while(!stk.empty() && a[stk.top()]>=a[i]) stk.pop();
        if(stk.empty()) rightSmall[i]=n;
        else rightSmall[i]=stk.top();
        stk.push(i);
    }

    vector<int>ans(n,INT_MIN);
    for(int i=0;i<n;i++){
        int len=rightSmall[i]-leftSmall[i]-1;
        ans[len-1]=max(ans[len-1],a[i]);
    }
    for(int i=n-2;i>=0;i--){
        ans[i]=max(ans[i],ans[i+1]);
    }

    return ans;
}