double median(vector<int>& a, vector<int>& b) {
	//brute force-->O(NlogN) if merge and sort and traverse
	//brute force -2 --> O(M+N) if traverse and get onto the required position, just lie we do in merge func

	//optimal O(min(logN,logM))
	if(b.size()<a.size()) return median(b, a);

	int m=a.size();
	int n=b.size();

	int low=0,high=m;
	int medianPos=(n+m+1)/2;
	while(low<=high){
		int cut1=low+(high-low)/2;//cut made in first array
		int cut2=medianPos-cut1;//cut made at second array

		int l1= cut1==0 ? INT_MIN : a[cut1-1];
		int l2= cut2==0 ? INT_MIN : b[cut2-1];
		int r1= cut1==m ? INT_MAX : a[cut1];
		int r2= cut1==n ? INT_MAX : b[cut2];

		if(l1<=r2 && l2<=r1){
			if((m+n)%2==0){
				return (max(l1,l2)+min(r1,r2))/2.0;
			}
			else return max(l1,l2);
		}
		else if(l1>r2) high = cut1-1;
        else low = cut1+1;
	}
	return 0;

}