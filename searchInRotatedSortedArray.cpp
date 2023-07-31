int search(int* arr, int n, int key) {
    int low=0, high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==key) return mid;
        else if(arr[low]<=arr[mid]){
            //left portion is sorted, now check if key belongs to here or not
            if(key<=arr[mid] && key>=arr[low]) high=mid-1;
            else low=mid+1;
        }
        else{
            //right portion is sorted, now check if key belongs to here or not
            if(key<=arr[high] && key>=arr[mid]) low=mid+1;
            else high=mid-1;
        }
    }
    return -1;
}