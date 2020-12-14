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
    int N,K;
    cin>>N>>K;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int count = 0;
    int i = N-1;
    while(K>0){
        if(K-arr[i]>=0){
            K=K-arr[i];
            count++;
        }else{
            i--;
        }
    }
    cout<<count;

 
    return 0;

}