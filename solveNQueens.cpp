bool isPossible(int row, int col, int n, vector<vector<int>>&ans){
    for(int j=0;j<n;j++){
        if(ans[row][j]==1) return false;
    }
    for(int i=0;i<n;i++){
        if(ans[i][col]==1) return false;;
    }
    int i=row,j=col;
    while(i>=0 && j<n){
        if(ans[i][j]==1) return false;
        i--; j++;
    }
    i=row;j=col;
    while(i>=0 && j>=0){
        if(ans[i][j]==1) return false;
        i--; j--;
    }

    return true;
}

void solve(int row, int n, vector<vector<int>>&ans, vector<vector<int>>&res){
    if(row==n){
        vector<int>temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back(ans[i][j]);
            }
        }
        res.push_back(temp);
        return;
    }

    for(int col=0;col<n;col++){
        if(isPossible(row,col,n,ans)){
            ans[row][col]=1;
            solve(row+1, n, ans, res);
            ans[row][col]=0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>>res;
    vector<vector<int>>ans(n,vector<int>(n,0));
    solve(0,n,ans,res);
    return  res;
}