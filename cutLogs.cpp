#include<bits/stdc++.h>

int dp[104][10004];
int solve(int k, int n){
    if(n==1 || n==0) return n;
    if(k==1) return n;//we have only 1 axe left, then we have to chcek for all capacities of dexk i.e n

    if(dp[k][n]!=-1) return dp[k][n];

    int low=1,high=n,ans=1e9;
    while(low<=high){
        int mid=low+(high-low)/2;

        int axeBroken=solve(k-1,mid-1);//axe vroke, not one less axe is available, and check for cutting mid-1 logs with them
        int noAxeBroken=solve(k,n-mid);//k axes can cut mid number of logs, so no axe is broken

        ans=min(ans,1+max(noAxeBroken,axeBroken));
        if(axeBroken<noAxeBroken){
            low=mid+1;
        }
        else high=mid-1;
    }

    return dp[k][n]=ans;
}
int cutLogs(int k, int n)
{
    // //RECURSIVE/MEMOIZED APPROACH
    // int ans=n;
    // memset(dp,-1,sizeof(dp));
    // return solve(k,n); 

    //DP
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=k;i++){
        dp[i][1]=1;
    }
    for(int j=1;j<=n;j++){
        dp[1][j]=j;
    }

    for(int i=2;i<=k;i++){
        for(int j=2;j<=n;j++){
            // int ans=1e9;
            // for(int t=1;t<=j;t++){
            //     int op1=dp[i][j-t];//axe is not broken, now determine in remaining capacity, i.e less than mid floors
            //     int op2=dp[i-1][t-1];//axe is broken

            //     ans=min(ans,1+max(op1,op2));
            // }
            // dp[i][j]=ans;
            //covering all exeeds time limit

            //do binary search
            int low=1,high=j,ans=1e9;
            while(low<=high){
                int mid=low+(high-low)/2;

                int op1=dp[i][j-mid];
                int op2=dp[i-1][mid-1];

                ans=min(ans,1+max(op1,op2));

                if(op1>op2) low=mid+1;
                else high=mid-1;
            }
            dp[i][j]=ans;
        }
    }
    return dp[k][n];
}















///////////////////SIMILAR TO EGG DROP PROBLEM /////////////////////
// #include<bits/stdc++.h>

// int dp[104][10004];
/* int solve(int e, int f) {
    if(f == 1 or f == 0)
        return f;
    
    if(e == 1)
        return f; // if onyl one egg is left then u have to check every floor;

    if(dp[e][f] != -1)
        return dp[e][f];

    int low = 1, high = f, ans = 1e9;
    while(low <= high) {
        int mid = (low + high) >> 1;
        int down = solve(e - 1, mid - 1); // egg break at mid, floors left is mid - 1
        int up = solve(e, f - mid); // no egg break, floors left are no.of floors - mid

        ans = min(ans, 1 + max(down, up));
        if(down < up)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return dp[e][f] = ans;
}

int cutLogs(int k, int n)
{
    memset(dp, -1, sizeof(dp));
    return solve(k, n); // k -> eggs, n -> floor
} */


/* int cutLogs(int k, int n) {
    memset(dp, 0, sizeof(dp));
    for(int e = 1; e <= k; e++)
        dp[e][1] = 1;

    for(int f = 1; f <= n; f++)
        dp[1][f] = f;

    for(int e = 2; e <= k; e++) {
        for(int f = 2; f <= n; f++) {
            int low = 1, high = f, ans = INT_MAX;
            while(low <= high) {
                int mid = (low + high) >> 1;
                int down = dp[e - 1][mid - 1];
                int up = dp[e][f - mid];

                ans = min(ans, 1 + max(down, up));
                if(up > down)
                    low = mid + 1;
                else 
                    high = mid - 1;
            }

            dp[e][f] = ans;
        }
    }
    
    return dp[k][n];
} */

// int cutLogs(int k, int n) {
//     vector<int> prev(n + 1, 0), curr(n + 1, 0);
//     prev[1] = 1;

//     for(int f = 1; f <= n; f++)
//         prev[f] = curr[f] = f;

//     for(int e = 2; e <= k; e++) {
//         for(int f = 2; f <= n; f++) {
//             int low = 1, high = f, ans = INT_MAX;
//             while(low <= high) {
//                 int mid = (low + high) >> 1;
//                 int down = prev[mid - 1];
//                 int up = curr[f - mid];

//                 ans = min(ans, 1 + max(down, up));
//                 if(up > down)
//                     low = mid + 1;
//                 else 
//                     high = mid - 1;
//             }

//             curr[f] = ans;
//         }
//         prev = curr;
//     }
    
//     return prev[n];
// }