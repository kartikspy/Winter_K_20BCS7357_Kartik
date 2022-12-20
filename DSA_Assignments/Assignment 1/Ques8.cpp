#include<bits/stdc++.h>
using namespace std;

void Cycle(int arr[],int k,int n){
    while(k--){
    int temp=arr[n-1];
    for(int i=n-1; i>0;i--){
     arr[i]=arr[i-1];
    }
    arr[0]=temp;
    }
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
}

int main(){
    int arr[]={2,5,1,7,3,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k;
    cin>>k;
    Cycle(arr,k,n);
     
}
