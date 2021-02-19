#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int dp[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=1;
        }
    }

    for(int i=0;i<puddles.size();i++){
        int y = puddles[i][1];
        int x = puddles[i][0];
        dp[y][x]=0;
        if(y==1){
            for(int j=x;j<=m;j++){
                dp[1][j]=0;
            }
        }
        if(x==1){
            for(int j=y;j<=n;j++){
                dp[j][1]=0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(dp[i][j]!=0){
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%1000000007;
            }
        }
    }

    answer=dp[n][m];
    return answer;
}