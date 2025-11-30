#include <bits/stdc++.h>
#include <cmath>
using namespace std;

void mergeArray(int arr[],int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++;
        }
        else{
            arr[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=b[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int r){
    if(l>=r) return;
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    mergeArray(arr,l,mid,r);
}

int main(){
    int arr[]={2,6,1,9,2,4};
    mergeSort(arr,0,5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}

// {2,6,1,9,2,4}
// break -> {2,6,1}  {9,2,4}
// {2,6,1} -> {2,6} and {1}
// {2,6} -> {2} {6} -> {2,6}
// merge {2,6} & {1} -> {1,2,6}
// {9,2,4} -> {9,2} and {4}
// {9,2} -> {9} {2} -> {2,9}
// merge {2,9} & {4} -> {2,4,9}
// final merge {1,2,6} & {2,4,9}
//  1,2,2,4,6,9

