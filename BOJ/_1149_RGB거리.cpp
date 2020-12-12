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
    int rgb[N][3];
    for(int i=0;i<N;i++){
        cin>>rgb[i][0]>>rgb[i][1]>>rgb[i][2];
    }
    int dp[N][3];
    dp[0][0]=rgb[0][0];
    dp[0][1]=rgb[0][1];
    dp[0][2]=rgb[0][2];
    
    for(int i=1;i<N;i++){
        dp[i][0] = min(dp[i-1][1],dp[i-1][2])+rgb[i][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2])+rgb[i][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1])+rgb[i][2];
    }
    int answer = min(dp[N-1][0],min(dp[N-1][1],dp[N-1][2]));
    cout<<answer;
    
    
    
    return 0;

}