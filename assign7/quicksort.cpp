#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int partitionIndex(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;

    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    int temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;
    return i+1;
}

void quickSort(int arr[],int l,int r){
    if(l<r){
        int p=partitionIndex(arr,l,r);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,r);
    }
}

int main(){
    int arr[]={2,6,1,9,2,4};

    quickSort(arr,0,5);

    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}

// {2,6,1,9,2,4}
// pivot = 4
// elements less than pivot moved left
// {2,1,2,4,9,6}
// left {2,1,2}
// right {9,6}
// sort left
// pivot = 2
// {1,2,2}
// sort right
// pivot = 6
//  {6,9}
// final {1,2,2,4,6,9}

