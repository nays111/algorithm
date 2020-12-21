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
    int dp[10001];
    int N;
    cin>>N;
    dp[0] = 0;
    int arr[10001];
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            dp[i] = max(dp[i],dp[i-j]+arr[j]);
        }
    }
    cout<<dp[N];
    return 0;
}