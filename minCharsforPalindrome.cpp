#include<bits/stdc++.h>
// int LCS(string& s1, string&s2){
// 	int n=s1.length();
// 	int m=s2.length();

// 	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
// 	for(int i=1;i<=n;i++){
// 		for(int j=1;j<=m;j++){
// 			if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
// 			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
// 		}
// 	}
// 	return dp[n][m];
// }

vector<int>LPS(string str){
	int j=0,i=1;
	vector<int>lps(str.length());
	while(i<str.length()){
		if(str[i]==str[j]){
			lps[i]=j+1;
			i++; j++;
		}
		else{
			if(j==0){
				lps[i]=0;
				i++;
			}else{
				j=lps[j-1];
			}
		}
	}
	return lps;
}
int minCharsforPalindrome(string str) {
	// string revStr=str;
	// reverse(revStr.begin(),revStr.end()); 
	// return str.length()-LCS(str,revStr);//if insertion allowed at any place, but question is to insert at front only


	//KMP
	string rev=str;
	reverse(rev.begin(),rev.end());
	string s=str+'$'+rev;
	vector<int>lps=LPS(s);
	return str.length()-lps.back();

	//can be done using Z algorithm also, but making of z array is comparitively tough
	// concatenate str+'$'+revStr;
	//construct z array for this, 
	// find max of all zarray elements
	// now return ans=str.length-maxElement
}
