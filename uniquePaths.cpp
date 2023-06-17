#include <bits/stdc++.h> 
int uniquePaths(int m, int n) { 
	int N=m+n-2;
	int R=m-1;
	//ans=nCr
	int ans=1;
	for(int i=0;i<R;i++){
		ans*=(N-i);
		ans/=(i+1);
	}
	return ans;
}