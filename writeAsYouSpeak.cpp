#include <bits/stdc++.h> 
void func(string str, int N, string&ans){
	if(N==1){ ans=str; return;}

	int cnt=1;
	string temp="";
	for(int i=0;i<str.length();i++){
		if(i==str.length()-1) temp+=to_string(cnt)+str[i];
		else if(str[i]==str[i+1]) cnt++;
		else{
			temp+=to_string(cnt)+str[i];
			cnt=1;
		}
	}

	func(temp,N-1,ans);
}
string writeAsYouSpeak(int n) 
{
	if(n==1) return "1";
	
	string ans;
	func("1",n,ans);
	return ans;	
}