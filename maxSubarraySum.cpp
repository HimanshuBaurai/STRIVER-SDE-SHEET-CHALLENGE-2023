#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    //kadane's algo 
    long long maxSum=LONG_MIN;
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum<0) sum=0;
        maxSum=max(maxSum,sum);
    }

    return maxSum; 
}