#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	//approach-> using map/set
	// unordered_map<int,int>freq;
	// for(auto num: arr){
	// 	if(freq.count(num)) return num;
	// 	else freq[num]++;
	// } 

	//using fast and slow poiter approach, just like linkedList
	int fast=0,slow=0;
	do{
		slow=arr[slow];
		fast=arr[arr[fast]];
	}while(fast!=slow);

	slow=0;
	while(slow!=fast){
		slow=arr[slow];
		fast=arr[fast];
	}
	return slow;

}
