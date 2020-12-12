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

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin>>N>>M;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int max = 0;
    for(int i=0;i<N-2;i++){
        for(int j=i+1;j<N-1;j++){
            for(int k=j+1;k<N;k++){
                if(arr[i]+arr[j]+arr[k]<=M && arr[i]+arr[j]+arr[k]>max){
                    max=arr[i]+arr[j]+arr[k];
                }
            }
        }
    }
    cout<<max;
    
    
    return 0;

}