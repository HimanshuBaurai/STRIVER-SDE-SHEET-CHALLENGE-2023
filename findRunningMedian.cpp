#include <bits/stdc++.h>

void findMedian(int *arr, int n)
{
    vector<int>result;

	priority_queue<int>maxHeap;
	priority_queue<int,vector<int>,greater<int>>minHeap;

	for(int i=0;i<n;i++){
        int num=arr[i];

		maxHeap.push(num);
		minHeap.push(maxHeap.top()), maxHeap.pop();
		if(minHeap.size()>maxHeap.size()){
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
        
		int median;
		if(maxHeap.size()>minHeap.size()){
			median=maxHeap.top();
		}
		else median=floor((maxHeap.top()+minHeap.top())/2.0);

		result.push_back(median);
	}

	for(auto m: result){
        cout<<m<<" ";
    }
}