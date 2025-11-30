#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
    int arr[]={2,6,1,9,2,4};
    for(int i=0;i<6-1;i++){
        int sml_pt=i;
        for(int j=i;j<6;j++){
            if(arr[j]<=arr[sml_pt]){
                sml_pt=j;
                
            }
        }
        int temp=arr[i];
        arr[i]=arr[sml_pt];
        arr[sml_pt]=temp;
    }

    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}



//{2,6,1,9,2,4} -> {1,6,2,9,2,4}
//{1,6,2,9,2,4} -> {1,2,6,9,2,4}
//{1,2,6,9,2,4} -> {1,2,2,9,6,4}
//{1,2,2,9,6,4} -> {1,2,2,4,6,9}