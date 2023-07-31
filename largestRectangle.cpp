#include <bits/stdc++.h>
 
 int largestRectangle(vector < int > & heights) {
   stack<int>stk;
   int n=heights.size();
   vector<int>leftFirstMin(n);
   for(int i=0;i<n;i++){
     while(!stk.empty() && heights[stk.top()]>=heights[i]) stk.pop();
     if(stk.empty()) leftFirstMin[i]=-1;
     else leftFirstMin[i]=stk.top();
     stk.push(i);
   }

   while(!stk.empty()) stk.pop();

   vector<int>rightFirstMin(n);
   for(int i=n-1;i>=0;i--){
     while(!stk.empty() && heights[stk.top()]>=heights[i]) stk.pop();
     if(stk.empty()) rightFirstMin[i]=n;
     else rightFirstMin[i]=stk.top();
     stk.push(i);
   }

   int maxArea=0;
   for(int i=0;i<n;i++){
     int width=rightFirstMin[i]-leftFirstMin[i]-1;
     int height=heights[i];
     int area=height*width;

     if(area>maxArea) maxArea=area;
   }

   return maxArea;
 }