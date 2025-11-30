#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
    int arr[]={2,6,1,9,2,4};
    for(int i=1;i<6;i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j=j-1;
        }

    }
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}

//{2,6}
//{2,6,1} -> {2,1,6} -> {1,2,6}
//{1,2,6,9}
//{1,2,6,9,2} -> {1,2,6,2,9} -> {1,2,2,6,9}