string kthPermutation(int n, int k) {
    string sequence="";
    for(int i=1;i<=n;i++){
        sequence+=to_string(i);
    }

    vector<int>fact(n+1,1);
    for(int i=1;i<=n;i++){
        fact[i]=fact[i-1]*i;
    }

    k--;
    string ans="";

    for(int i=n-1;i>=0;i--){
        int index=k/fact[i];
        k%=fact[i];

        ans+=sequence[index];
        sequence.erase(sequence.begin()+index);
    }

    return ans;
}
