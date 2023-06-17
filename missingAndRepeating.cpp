#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// //brute force, count using freq map
	// unordered_map<int,int>mpp;
	// for(auto num: arr)
	//    mpp[num]++;
	// int missingNum,repeatingNum;
	// for(int i=1;i<=n;i++){
	// 	if(mpp.count(i)==0) missingNum=i;
	// 	else if(mpp[i]==2) repeatingNum=i;
	// }
	// return {missingNum,repeatingNum};

	//optimal -->XOR
	int XorAll=0,Xor1ToN=0;
	for(int i=1;i<=n;i++){
		XorAll^=arr[i-1];
		Xor1ToN^=i;
	}

	int a=XorAll^Xor1ToN;
	int index=0;//rightmost set bit index
	while(index<32){
		if((1<<index)&a)break;
		index++;
	}
	int Xor1=0,Xor2=0;//xor1 is xor of all elemnts and number 1-N having bit at index index as set, and xor2 is just opposite
	for(int i=0;i<n;i++){
		if(arr[i]&(1<<index)) Xor1^=arr[i];
		else Xor2^=arr[i];

		if((i+1)&(1<<index)) Xor1^=(i+1);
		else Xor2^=(i+1);
	}
	bool xor1Found=false;
	for(int i=0;i<n;i++){
		if(arr[i]==Xor1){
			xor1Found=true;
			break;
		}
	}
	if(xor1Found){
		return {Xor2,Xor1};
	}
	else return {Xor1,Xor2};
}
