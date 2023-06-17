#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long>>triangle(n);
  for(int i=0;i<n;i++){
    triangle[i].resize(i+1,1);
    for(int j=1;j<i;j++){
      triangle[i][j]=triangle[i-1][j]+triangle[i-1][j-1];
    }
  }
  return triangle;
}
