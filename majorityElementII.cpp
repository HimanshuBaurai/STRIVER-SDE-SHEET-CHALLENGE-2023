#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    //brute force, simple counting freq;
    

    //optimal bayer moore algo
    int n=arr.size();
    vector<int>ans;
    int cnt1=0,cnt2=0;
    int num1=-1,num2=0;

    for(int i=0;i<n;i++){
        if(arr[i]==num1) cnt1++;
        else if(arr[i]==num2) cnt2++;
        else if(cnt1==0){ num1=arr[i]; cnt1=1; }
        else if(cnt2==0){ num2=arr[i]; cnt2=1; }
        else{ cnt1--; cnt2--; }
    }

    cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==num1) cnt1++;
        else if(arr[i]==num2) cnt2++;
    }
    if(cnt1>floor(n/3)) ans.push_back(num1);
    if(cnt2>floor(n/3)) ans.push_back(num2);
    return ans;

}