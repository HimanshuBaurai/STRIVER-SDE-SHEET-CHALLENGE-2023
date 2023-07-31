#include <bits/stdc++.h> 

bool isPalindrome(string& str){
    int i=0,j=str.length()-1;
    while(i<j){
        if(str[i++]!=str[j--]) return false;
    }
    return true;
}
void helper(int index, int len, string&s, vector<vector<string>>&ans, vector<string>&temp){
    if(index==len){
        ans.push_back(temp);
        return;
    }

    string str="";
    for(int i=index;i<len;i++){
        str+=s[i];
        if(isPalindrome(str)){
            temp.push_back(str);
            helper(i+1,len,s,ans,temp);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    vector<vector<string>>ans;
    vector<string>temp;
    helper(0,s.length(),s,ans,temp);
    return ans;
}