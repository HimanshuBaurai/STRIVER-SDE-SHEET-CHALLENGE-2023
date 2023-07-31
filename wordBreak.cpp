#include <bits/stdc++.h> 

void func(int index, string&s, unordered_set<string>&dict, vector<string>&ans, string curr){
    if(index==s.length()){
        curr.pop_back();
        ans.push_back(curr);
        return;
    }

    string temp="";
    for(int i=index;i<s.length();i++){
        temp+=s[i];
        if(find(dict.begin(),dict.end(),temp)!=dict.end()){
            func(i+1,s,dict,ans,curr+temp+' ');
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_set<string>dict(dictionary.begin(),dictionary.end());
    vector<string>ans;
    func(0,s,dict,ans,"");
    return ans;
}