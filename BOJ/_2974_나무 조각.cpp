#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
#include <functional>
using namespace std;

int arr[15][15];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);  
    int arr[5];
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    while(1){
        for(int i=0;i<4;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                for(int j=0;j<5;j++){
                    cout<<arr[j]<<" ";
                }
                cout<<'\n';
            }
        }
        if(arr[0]==1 && arr[1]==2 && arr[2]==3 && arr[3]==4 && arr[4]==5){
                    break;
                }
    }
    return 0;
}