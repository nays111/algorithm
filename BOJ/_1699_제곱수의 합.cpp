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
    int N;
    cin>>N;
    int dp[100001];
    for(int i=0;i<=N;i++){
        dp[i] = i;
    }
    for(int i=2;i<=N;i++){
        for(int j=2;j*j<=i;j++){
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }
    }
    cout<<dp[N];
    return 0;
}