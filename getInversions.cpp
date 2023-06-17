#include <bits/stdc++.h> 

long long merge(long long*arr, int low, int mid, int high){
    long long ans=0;

    long long*temp= new long long[high-low+1];
    int i=low,j=mid+1,k=0;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++]; 
        }
        else{ 
            temp[k++]=arr[j++];
            ans+=(mid-i+1);
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=high){
        temp[k++]=arr[j++];
    }

    for(int ind=low;ind<=high;ind++){
        arr[ind]=temp[ind-low];
    }

    return ans;
}

long long MS(long long*arr, int low, int high){
    if(low>=high) return 0;

    long long ans=0;
    int mid=low+(high-low)/2;
    ans+=MS(arr,low,mid);
    ans+=MS(arr,mid+1,high);
    ans+=merge(arr,low,mid,high);
    return ans;
}
long long getInversions(long long *arr, int n){
    int low=0,high=n-1;
    return MS(arr,low,high);
}