
bool canPlace(int num, int row, int col, int matrix[9][9]){
    for(int i=0;i<9;i++){
        if(matrix[i][col]==num) return false;
    }
    for(int j=0;j<9;j++){
        if(matrix[row][j]==num) return false;
    }
    int rowFactor=row-row%3;
    int colFactor=col-col%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(matrix[i+rowFactor][j+colFactor]==num) return false;
        }
    }

    return true;
}
void getEmptySpace(int&row, int&col, int matrix[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j]==0){
                row=i; col=j;
                return;
            }
        }
    }
}
bool solve(int matrix[9][9]){
    int row=-1,col=-1;
    getEmptySpace(row,col,matrix);
    if(row==-1 || col==-1) return true;

    for(int i=1;i<=9;i++){
        if(canPlace(i,row,col,matrix)){
            matrix[row][col]=i;
            if(solve(matrix)) return true;
            matrix[row][col]=0;
        }
    }
    return false;
}

bool isItSudoku(int matrix[9][9]) {
    return solve(matrix);
}
