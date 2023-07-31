#include <bits/stdc++.h> 

bool isPossible(int n, int m, vector<int>&time, long long mid){
	long long cnt=1,taken=0;
	for(int i=0;i<m;i++){
		if(taken+time[i]<=mid) taken+=time[i];
		else{
			if(time[i]>mid || cnt>n) return false;
			taken=time[i];
			cnt++;
		}
	}
	return cnt<=n;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long low=0,high=0;
	for(auto num: time) high+=num;
    
	long long ans=-1;
	while(low<=high){
		long long mid=low+(high-low)/2;

		if(isPossible(n,m,time,mid)){
			ans=mid;
			high=mid-1;
		}
		else low=mid+1;
	}
	return ans;
}