#include <bits/stdc++.h>

vector<vector<int>>dirs={{-1,0},{1,0},{0,1},{0,-1}};
void solve(int i, int j, int n, vector<vector<int> > &maze, vector<vector<int> > &temp, vector<vector<int> > &ans){
  if(i==n-1 && j==n-1){
    vector<int>v;
    for(auto vec: temp){
      for(auto num: vec){
        v.push_back(num);
      }
    }
    ans.push_back(v);
    return;
  }

  for(auto& d: dirs){
    int x=i+d[0];
    int y=j+d[1];
    if(x<n && x>=0 && y<n && y>=0 && maze[x][y]==1 && temp[x][y]==0){
      temp[x][y]=1;
      solve(x,y,n,maze,temp,ans);
      temp[x][y]=0;
    }
  }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>>ans;
  if(maze[0][0]==0) return ans;

  vector<vector<int>>temp(n,vector<int>(n,0));
  temp[0][0]=1;
  solve(0,0,n,maze,temp,ans);
  return ans;
}