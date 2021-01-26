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
    int dp[1001][1001];
    int arr[1001][1001];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    dp[1][1]=arr[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = max(dp[i-1][j]+arr[i][j],max(dp[i-1][j-1]+arr[i][j],dp[i][j-1]+arr[i][j]));
        }
    }
    cout<<dp[n][m];
    
    
    return 0;
}