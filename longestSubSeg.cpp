#include <unordered_map>
int longestSubSeg(vector<int> &arr , int n, int k){
    unordered_map<int,int>mpp;
    int len=0;
    int i=0,j=0;
    while(j<n){
        mpp[arr[j++]]++;

        while(mpp[0]>k){ mpp[arr[i++]]--; }

        len=max(len,j-i);
    }
    return len;
}
