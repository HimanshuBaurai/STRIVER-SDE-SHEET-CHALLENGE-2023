#include <bits/stdc++.h>
// O(N2logN)
// string fourSum(vector<int> arr, int target, int n) {
//     sort(arr.begin(),arr.end()); 
//     for(int i=0;i<n;i++){
//         for(int j=i+3;j<n;j++){
//             int front=i+1,back=j-1;
//             int newTarget=target-(arr[i]+arr[j]);
//             while(front<back){
//                 int sum=arr[front]+arr[back];
//                 if(sum<newTarget)front++;
//                 else if(sum>newTarget) back--;
//                 else return "Yes";
//             }
//         }
//     }
//     return "No";
// }

//optimal
/*
    Time Complexity: O(N^2)
    Space complexity: O(N^2)

    Where 'N' is the number of element present in the given array.
*/

#include <unordered_map>
#include <vector>

bool commonIdx(pair < int, int > p1, pair < int, int > p2) {
    return p1.first == p2.first || p1.first == p2.second || p1.second == p2.first || p1.second == p2.second;
}

string fourSum(vector < int > arr, int target, int n) {
    unordered_map < int, pair < int, int >> mp;
    
    /* 
        Preparing a HashMap which will store sum of 
        two elements of array arr[] as key and their 
        indexes as value.
    */
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            mp[arr[i] + arr[j]] = {
                i,
                j
            };
        }
    }

    // Check on all possible pair sum which can be found in HashMap.
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int requiredSum = target - (arr[i] + arr[j]);
            /* 
                If HashMap contains required sum then we must 
                ensure that both pairs does not contain common indexes.
            */
            if (mp.find(requiredSum) != mp.end() && !commonIdx(mp[requiredSum], {
                    i,
                    j
                })) {
                return "Yes";
            }
        }
    }
    // If we can not found the target sum then we return No.
    return "No";
}