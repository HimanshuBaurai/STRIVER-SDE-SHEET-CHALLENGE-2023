#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int mini=INT_MAX;
    int maxProfit=0;
    for(auto p: prices){
        mini=min(mini,p);
        if(p-mini > maxProfit) maxProfit=p-mini;
    }
    return maxProfit;
}