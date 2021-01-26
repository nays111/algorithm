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
    int dp[31][31];
    for(int i=1;i<31;i++){
        dp[1][i]=i;
    }
    for(int i=1;i<31;i++){
        for(int j=1;j<31;j++){
            if(i==j){
                dp[i][j]=1;
            }
        }
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        for(int j=2;j<=a;j++){
            for(int k=3;k<=b;k++){
                if(j<k){
                    dp[j][k] = dp[j-1][k-1] + dp[j][k-1];
                }
            }
        }
        cout<<dp[a][b]<<'\n';
        

    }

    return 0;
}