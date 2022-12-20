#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[], int big, int mid,int end){
    int n1 = mid - big + 1;
    int n2 =  end- mid;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[big + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[mid + 1 + j];
    int i, j, k;
    i = 0;
    j = 0;
    k = big;
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[],int big,int  end){
    if(big>=end){
        return;
    }
    int mid=(big+end)/2;
    MergeSort(arr,big,mid);
    MergeSort(arr,mid+1,end);
    Merge(arr,big,mid,end);
}

int main(){
    int arr[]={2,7,1,9,3,5,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k;
    cin>>k;
    MergeSort(arr,0,n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
