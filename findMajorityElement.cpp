#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	//brute force simple counting freq

	//optimal-->moore voting algo
	int major=arr[0], count = 1;
    for(int i=1; i<n;i++){
        if(count==0){
            count++;
            major=arr[i];
        }else if(major==arr[i]){
            count++;
        }else count--;
        
    }
	
	count=0;
	for(int i=0;i<n;i++){
		if(arr[i]==major) count++;
	}
    return count>floor(n/2) ? major : -1;
}