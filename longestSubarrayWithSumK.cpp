int longestSubarrayWithSumK(vector<int> a, long long k) { 
  long long sum = 0;
  int i = 0, j = 0, n = a.size();
  int len = 0;
  while (j < n) {
    sum += (long long)a[j++]; 
    while (sum > k && i < j) {
      sum -= (long long)a[i++];
    }
    if (sum == k)
      len = max(len, j - i);
  }
  return len;
}