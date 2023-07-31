#include <bits/stdc++.h>

void helper(int index, vector<int>&arr, int n, int target, vector<vector<int>>&ans, vector<int>&temp){

	if(target==0){ ans.push_back(temp); return; }
 
    for(int i=index;i<n;i++){
		if(i>index && arr[i]==arr[i-1]) continue;
		if(arr[i]>target) break;

		temp.push_back(arr[i]);
		helper(i+1, arr, n, target-arr[i], ans, temp);
		temp.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	sort(arr.begin(),arr.end());

	vector<vector<int>>ans;
	vector<int>temp;
	helper(0,arr,n,target,ans,temp); 
	return ans;
}
