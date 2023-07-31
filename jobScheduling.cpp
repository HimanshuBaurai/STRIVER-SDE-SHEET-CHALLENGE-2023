#include <bits/stdc++.h> 
bool comp(vector<int>&a, vector<int>&b){
    if(a[1]>b[1]) return true;
    else if(a[1]==b[1]) return a[0]>=b[0];
    else return false;
}
int jobScheduling(vector<vector<int>> &jobs)
{
    int profit=0;
    int n=jobs.size();

    int maxDeadline=-1;
    for(int i=0;i<n;i++){
        maxDeadline=max(maxDeadline,jobs[i][0]);
    }

    sort(jobs.begin(),jobs.end(),comp);

    vector<int>slots(maxDeadline+1,-1);
    for(int i=0;i<n;i++){
        int d=jobs[i][0];
        for(int j=d;j>0;j--) {
            if(slots[j]==-1) {
                slots[j]=jobs[i][1];
                break;
            }
        } 
    }

    for(int i=0;i<=maxDeadline;i++){
        profit+= slots[i]==-1 ? 0 : slots[i];
    }

    return profit;
}
