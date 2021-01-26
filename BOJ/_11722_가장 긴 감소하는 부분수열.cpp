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
    int arr[1001];
    int dp[1001];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        dp[i] = 1;
    }
    int maxs = 0;
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[j]+1,dp[i]);
            }
        }
        if(dp[i]>maxs){
            maxs = dp[i];
        }
    }
    cout<<maxs;
    return 0;
}