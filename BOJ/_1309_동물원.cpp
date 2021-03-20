#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
using namespace std;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int dp[3][100001];
    dp[0][0]=dp[1][0]=dp[2][0]=1;
    for(int i=1;i<n;i++){
        dp[0][i]=(dp[0][i-1]+dp[1][i-1]+dp[2][i-1])%9901;
        dp[1][i]=(dp[0][i-1]+dp[2][i-1])%9901;
        dp[2][i]=(dp[0][i-1]+dp[1][i-1])%9901;
    }
    int answer = (dp[0][n-1] + dp[1][n-1] + dp[2][n-1])%9901;
    cout<<answer;

    return 0;

}