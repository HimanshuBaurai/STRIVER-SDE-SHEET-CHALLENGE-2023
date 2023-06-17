bool searchMatrix(vector<vector<int>>& mat, int target) {
    int rows=mat.size();
    int cols=mat[0].size();
    int i=0,j=cols-1;
    while(i<rows && j>=0){
        if(mat[i][j]==target) return true;
        else if(mat[i][j]<target) i++;
        else j--;
    }
    return false;
}