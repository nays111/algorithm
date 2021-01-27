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
    int dp[31];
    int n;
    cin>>n;
    dp[0]=1;
    dp[2]=3;
    for(int i=4;i<=n;i++){
        dp[i] = dp[i-2]*3;
        for(int j=4;j<=i;j+=2){
            dp[i] += dp[i-j]*2;//위 아래 (*2)
        }
    }
    cout<<dp[n];
    return 0;
}