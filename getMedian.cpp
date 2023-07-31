#include <bits/stdc++.h>

int countSmallerThanMid(vector<int> &row, int mid)
{
  int l = 0, h = row.size() - 1;
  while (l <= h)
  {
    int md = (l + h) >> 1;
    if (row[md] <= mid)
    {
      l = md + 1;
    }
    else
    {
      h = md - 1;
    }
  }
  return l;
}

int getMedian(vector<vector<int>> &matrix) {
  int N = matrix.size();
  int M = matrix[0].size();
  int num = (N * M) / 2;

  int maxi = 0;
  for (int i = 0; i < N; i++) {
    maxi = max(maxi, matrix[i][M - 1]);
  }
  
  int i = 1, j = maxi;
  while (i <= j) {
    int element = (i + j) / 2; 

    int cnt = 0;
    for (int row = 0; row < N; row++) {
      cnt += countSmallerThanMid(matrix[row], element);
    }
    if (cnt <= num)
      i = element + 1; 
    else
      j = element - 1;
  }
  return i;
}