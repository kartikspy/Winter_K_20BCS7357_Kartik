#include<bits/stdc++.h>
using namespace std;
int Missing(int arr[], int n, int a, int l){
  int sum=0,s;
  if((a+l)%2==0) 
    {
        s = (a+l)/2;
        s = s*(n+1);
    }
    else
    {
        s = (n+1)/2;
        s = (a+l)*s;
  
    }
  
  for(int i=0; i<n; i++){
    sum+=arr[i];
  }
  return (s-sum);
}
int main(){
    int arr[]={10,20,30,50,60,70};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ap,sum=0;
    int a=arr[0],l=arr[n-1];
    
    cout<<Missing(arr,n,a,l);
}
