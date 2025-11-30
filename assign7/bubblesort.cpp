#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
    int a[]={32,4,2,23,6,4,2,57};
    for(int i=7;i>0;i++){
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    for(int i=0;i<8;i++){
        cout<<a[i]<<" ";
    }
}