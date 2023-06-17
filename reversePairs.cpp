#include <bits/stdc++.h> 

int m(vector<int>&arr, int l, int mid, int h){
	int i=l,j=mid+1,k=0;

	int ans=0;
	for(;i<=mid;i++){
		while(j<=h && arr[i]>2*arr[j]) j++;
		ans+=j-(mid+1);
	}

	i=l,j=mid+1;
	vector<int>temp(h-l+1);
	while(i<=mid && j<=h){
		if(arr[i]<arr[j]){
			temp[k++]=arr[i++];
		}
		else{ 
			temp[k++]=arr[j++];
		}
	}
	while(i<=mid){
		temp[k++]=arr[i++];
	}
	while(j<=h){
		temp[k++]=arr[j++];
	}
	for(int ind=l;ind<=h;ind++){
		arr[ind]=temp[ind-l];
	}

	return ans;
}

int ms(vector<int>&arr, int l, int h){
	if(l>=h) return 0;

	int ans=0;
	int mid=l+(h-l)/2;
	ans+=ms(arr,l,mid);
	ans+=ms(arr,mid+1,h);
	ans+=m(arr,l,mid,h);
	return ans;
}
int reversePairs(vector<int> &arr, int n){ 	
	return ms(arr,0,n-1);
}