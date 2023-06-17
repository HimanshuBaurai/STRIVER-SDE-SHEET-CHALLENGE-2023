#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //dutch flag algo
   int next0=0,next2=n-1;
   int i=0;
   while(i<=next2){
      if(arr[i]==0){
         swap(arr[i++],arr[next0++]);  
      }
      else if(arr[i]==2){
         swap(arr[i],arr[next2--]); 
      }
      else i++;
   }
}