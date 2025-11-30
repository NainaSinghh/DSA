#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
    int arr[]={2,6,1,9,2,4};
    int n=6;

    int left=0,right=n-1;

    while(left<right){

        int minIndex=left;
        int maxIndex=right;

        if(arr[minIndex]>arr[maxIndex]){
            int t=arr[minIndex];
            arr[minIndex]=arr[maxIndex];
            arr[maxIndex]=t;
        }

        for(int i=left+1;i<right;i++){
            if(arr[i]<arr[minIndex]) minIndex=i;
            if(arr[i]>arr[maxIndex]) maxIndex=i;
        }

        int t1=arr[left];
        arr[left]=arr[minIndex];
        arr[minIndex]=t1;

        if(maxIndex==left) maxIndex=minIndex;

        int t2=arr[right];
        arr[right]=arr[maxIndex];
        arr[maxIndex]=t2;

        left++;
        right--;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
