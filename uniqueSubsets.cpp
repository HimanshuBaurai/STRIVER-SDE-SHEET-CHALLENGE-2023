#include <bits/stdc++.h>
void subset_helper(vector<int> &nums, int n, int idx, vector<int> &res,
                   vector<vector<int>> &ans) {

  ans.push_back(res);

  for (int i = idx; i < n; i++) {
    if (i != idx && nums[i] == nums[i - 1])
      continue;
    res.push_back(nums[i]);
    subset_helper(nums, n, i + 1, res, ans);
    res.pop_back();
  }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &nums) {
  // optimal 
  vector<vector<int>> ans;
  vector<int> res;
  sort(nums.begin(), nums.end());
  subset_helper(nums, n, 0, res, ans);
  return ans;
}