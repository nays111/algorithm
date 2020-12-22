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
int arr[1001];
int dp[1001];
int memo[1001];

void printArr(int p){
    if(p==-1){
        return;
    }
    printArr(memo[p]);
    cout<<arr[p]<<' ';
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int dp[N];
    dp[0] = arr[0];
    for(int i=1;i<N;i++){
        dp[i] = max(dp[i-1]+arr[i],arr[i]);
    }
    int max = dp[0];
    for(int i=1;i<N;i++){
        if(max <dp[i]){
            max = dp[i];
        }
    }
    cout<<max;
    return 0;
}