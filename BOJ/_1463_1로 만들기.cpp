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
    int dp[1000001]={0,};
    dp[1]=0;
     for(int i = 2; i <= N; i++) {
        dp[i] = dp[i-1] + 1;
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
    }
    cout<<dp[N];
    return 0;

}