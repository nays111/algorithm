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
    
    long long dp[32][32];
    
    for(int i=0;i<31;i++){
        dp[1][i] =i+1;
    }
    for(int i=0;i<31;i++){
        dp[0][i] = 1;
    }
    dp[0][0]=0;
    dp[1][0]=1;
    dp[2][0]=2;
    dp[3][0]=5;
    for(int i=2;i<31;i++){
        for(int j=0;j<31;j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j+1];
            dp[i][0] = dp[i-1][1];
        }
    }
    // for(int i=0;i<10;i++){
    //     for(int j=0;j<10;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    
    
    while(1){

        int target;
        cin>>target;
        if(target==0){
            break;
        }
        
        cout<<dp[target-1][1]<<'\n';

        
    }

    
    
    return 0;
}