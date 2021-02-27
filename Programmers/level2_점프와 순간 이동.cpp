#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    // long long a = n;
    // long long dp[a+1];
    // dp[0]=0;
    // dp[1]=1;
    // dp[2]=1;
    // for(long long i=3;i<=n;i++){
    //     if(i%2==0){
    //         dp[i]=dp[i/2];
    //     }else{
    //         dp[i]=dp[i-1]+1;
    //     }
    // }
    // ans=dp[a];
    // cout<<ans;
    while(n>0){
        if(n%2==0){
            n=n/2;
        }else{
            n--;
            ans++;
        }
    }

    return ans;
}