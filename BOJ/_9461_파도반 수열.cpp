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
    long dp[100];
    dp[0]=1;
    dp[1]=1;
    dp[2]=1;
    dp[3]=2;
    dp[4]=2;
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        for(int i=5;i<n;i++){
            dp[i]=dp[i-1]+dp[i-5];
        }
        cout<<dp[n-1]<<endl;
        
    }



    return 0;

}