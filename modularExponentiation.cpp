#include <bits/stdc++.h>
// //RECURSIVE
// int modularExponentiation(int x, int n, int m) {
// 	if(n==0) return 1; 

// 	int ans=modularExponentiation(x, n/2, m);

// 	if(n&1) return (x*((ans*1ll*ans)%m))%m;
// 	else return (ans*1ll*ans)%m;
// }

//ITERATIVE
int modularExponentiation(int x, int n, int m) {
	int res=1;

	while(n>0){
		if(n&1){
			res=(res*1ll*x)%m; //-->res=res*x
		}
		x=(x*1ll*x)%m;//-->x=x*x
		n=n>>1;//-->n=n/2
	}
	return res%m;
}