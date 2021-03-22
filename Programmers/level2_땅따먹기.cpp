#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    int dp[100001][5];
    int n = land.size();
    dp[1][1] = land[0][0];
    dp[1][2] = land[0][1];
    dp[1][3] = land[0][2];
    dp[1][4] = land[0][3];
    for(int i=2;i<=n;i++){
        dp[i][1] = land[i-1][0]+max(dp[i-1][2],max(dp[i-1][3],dp[i-1][4]));
        dp[i][2] = land[i-1][1]+max(dp[i-1][1],max(dp[i-1][3],dp[i-1][4]));
        dp[i][3] = land[i-1][2]+max(dp[i-1][1],max(dp[i-1][2],dp[i-1][4]));
        dp[i][4] = land[i-1][3]+max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=4;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    for(int j=1;j<=4;j++){
        answer = max(answer,dp[n][j]);
    }

    return answer;
}