#include <bits/stdc++.h>

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis,
         stack<int> &stk) {
  vis[node] = true;
  for (auto adjNode : adj[node]) {
    if (!vis[adjNode]) {
      dfs(adjNode, adj, vis, stk);
    }
  }
  stk.push(node);
}

void dfs3(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int>&temp) {
  vis[node] = true;
  temp.push_back(node);
  for (auto adjNode : adj[node]) {
    if (!vis[adjNode]) {
      dfs3(adjNode,adj, vis,temp);
    }
  }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges) {
  vector<vector<int>> adj(n);
  for (auto edge : edges) {
    adj[edge[0]].push_back(edge[1]);
  }

  vector<bool> vis(n, false);
  stack<int> stk;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i, adj, vis, stk);
    }
  }

  //   rerverse graph
  vector<vector<int>> adjT(n);
  for (int i = 0; i < n; i++) {
    vis[i] = false;
    for (auto adjNode : adj[i]) {
      adjT[adjNode].push_back(i);
    }
  }

  int cnt = 0;
  vector<vector<int>>res;
  // reverse dfs
  while (!stk.empty()) {
    int node = stk.top();
    stk.pop();
    if (!vis[node]) {
      cnt++;
      vector<int>temp;
      dfs3(node, adjT, vis, temp);
      res.push_back(temp);
    }
  }
  return res;
}