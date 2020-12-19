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
    long long dp[101][11];
    //N=1일 때 1의 9는 한번씩 체크
    for(int i=1;i<=9;i++){
        dp[1][i]=1;
    }
    dp[1][0] = 0;
 
    for(int i=2;i<=N;i++){     
        for(int j=0;j<=9;j++){
            if(j==0){
                dp[i][0] = (dp[i-1][i+1])%1000000000;//어차피 무조건 1나옴
            }else if(j==9){
                dp[i][9] = (dp[i-1][j-1])%1000000000;
            }else{
                dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%100000000;
            }
            
        }
    }
    long long sum = 0;
    for(int i=0;i<10;i++){
        sum=sum+dp[N][i];
    }
    cout<<sum%1000000000;

    return 0;
}