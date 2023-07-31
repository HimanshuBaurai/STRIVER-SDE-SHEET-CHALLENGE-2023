#include <bits/stdc++.h>
using namespace std;
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k)
{
    // Write your code here.
    if (n < m)
        return ninjaAndLadoos(row2, row1, n, m, k);

    int l = max(0, k - n), h = min(k, m);
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        int cut1 = mid;
        int cut2 = k - cut1;

        int l1 = cut1 == 0 ? INT_MIN : row1[cut1 - 1];
        int r1 = cut1 == m ? INT_MAX : row1[cut1];
        int l2 = cut2 == 0 ? INT_MIN : row2[cut2 - 1];
        int r2 = cut2 == n ? INT_MAX : row2[cut2];

        if (l1 <= r2 && l2 <= r1)
            return max(l1, l2);
        else if (l1 > r2)
            h = cut1 - 1;
        else
            l = cut1 + 1;
    }
    return 1;
}

int solution(vector<string> patterns)
{
    int m = patterns[0].length();
    int n = patterns.size();
    string ans;
    for (int j = 0; j < m; j++)
    {
        set<char> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(patterns[i][j]);
        }
        if (st.size() == 1 || (st.count('?') && st.size() == 2))
        {
            if (st.size() == 1)
            {
                if(st.count('?') == 0) ans.push_back(*st.begin());
                else ans.push_back('c');
            }
            else if (st.size() == 2 && st.count('?'))
            {
                set<char>::iterator it=st.begin();

                char ch1 =*it;
                it++; 
                char ch2 = *it; 
                if (ch1 != '?')
                    ans.push_back(ch1);
                else
                    ans.push_back(ch2);
            }
        }
        else
            ans.push_back('?');
    }

    int cnt=0;
    for(auto ch:ans){
        if(ch=='?') cnt++;
    }
    return cnt;
}

int main(){
    // vector<string>p={"ha???rrank","?a?ke?bank"};
    vector<string>p={"bug","gub","g?a"};
    cout<<solution(p);
    return 0;
}