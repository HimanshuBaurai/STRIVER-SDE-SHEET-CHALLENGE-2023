#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int>ans(n);
    stack<int>stk;
    for(int i=n-1;i>=0;i--){
        while(!stk.empty() && arr[stk.top()]<=arr[i]) stk.pop();
        if(stk.empty()) ans[i]=-1;
        else ans[i]=arr[stk.top()];

        stk.push(i);
    }
    return ans;
}