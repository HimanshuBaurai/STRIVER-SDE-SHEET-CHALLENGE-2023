void func(int index, vector<int>&arr, int n, int reqSum, vector<vector<int>>&res, vector<int>&ans){
    if(index==n){
        if(reqSum==0) res.push_back(ans);
        return;
    }

    func(index+1,arr,n,reqSum,res,ans);
    
    ans.push_back(arr[index]);
    func(index+1,arr,n,reqSum-arr[index],res,ans);
    ans.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>>res;
    vector<int>ans;
    func(0,arr,n,k,res,ans);
    return res;
}