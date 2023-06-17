#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    if(n==1) return permutation;

    //based on dictionary ordering
    //first index from back where the element is smaller than the ahead one
    int index1,index2;
    for(index1=n-2;index1>=0;index1--){
        if(permutation[index1]<permutation[index1+1]){ 
            break;
        }
    }
    if(index1<0){
        //sorted indesc order, just reverse the whole array
        reverse(permutation.begin(),permutation.end());
        return permutation;
    }
    else{
        //first index from back where the element is greater than the index1
        for(index2=n-1;index2>index1;index2--){
            if(permutation[index2]>permutation[index1]){ 
                break;
            }
        }
        //now swap index1,index2;
        swap(permutation[index1],permutation[index2]);
        //now reverse the array from index1+1 to last
        reverse(permutation.begin()+index1+1,permutation.end());
        return permutation;
    }
}