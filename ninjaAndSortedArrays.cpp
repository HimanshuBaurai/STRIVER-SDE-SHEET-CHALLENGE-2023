#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	/////////////APPROACH-1////////////////////
	//brute force O(NlogN) time complexity and O(1) space complexity
	// add all elements into arr1, and sort it and return 
	for(int i=m;i<m+n;i++){
		arr1[i]=arr2[i-m];
	}
	sort(arr1.begin(),arr1.end());
	return arr1;


     /////////////APPROACH-2////////////////////
	//optimized approach O(M+N) is time complexity, but space complexity increase to O(M+N)
	// use 2 pointers to simlutaneously iterate over arr1 and arr2, and place the elements ito the resultant vector
	vector<int>res(m+n);
	int i=0,j=0,k=0;
	while(i<m&&j<n){
		if(arr1[i]<arr2[j]){
			res[k++]=arr1[i++];
		}
		else res[k++]=arr2[j++];
	}
	//if arr1 has some elements left in it, ao add them into result vector
	while(i<m){
		res[k++]=arr1[i++];
	}
	//similarly for arr2
	while(j<n){
		res[k++]=arr2[j++];
	}
	return res;

    /////////////APPROACH-3////////////////////
	//optimal approach Gap algorithm O(NlogN) and space complexity O(1)
	for(int i=m;i<m+n;i++){
		arr1[i]=arr2[i-m];
	}
	int gap=ceil((float)(m+n)/2.0);
	while(gap>=1){
		int i=0;
		while(i+gap<m+n){
			if(arr1[i]>arr1[i+gap]){
				swap(arr1[i],arr1[i+gap]);
			}
			i++;
		}
		if(gap==1) gap=0;
		else gap=ceil((float)gap/2.0);
	}
	return arr1;
}