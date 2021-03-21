#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n) {
    long long answer = 0;

    long long dp[2001];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i] = (dp[i-1]+dp[i-2])%1234567;
    }
    cout<<dp[n];
    answer  = dp[n];
    return answer;
}