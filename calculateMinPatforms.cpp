int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);
    sort(dt,dt+n);
    int train=0,platform=0;
    int i=0,j=0;
    while(i<n&&j<n){
        if(at[i]<=dt[j]){ i++; train++; }
        else{ train--; j++; }
        platform=max(platform,train);
    }
    return platform;
}