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
    /*
    dp[N] = N을 1,2,3의 합으로 나타내는 방법의 수
    (합 : n-1) + 1 = n
    (합 : n-2) + 2 = n
    (합 : n-3) + 3 = n
    즉, dp[n] = dp[n-1] + dp[n-2] + dp[n-3]
    */
    int dp[12];
    dp[0] = 1;//0을 만드는 경우는 수를 0개씩 사용하는 방법 1가지가있다.
    dp[1] = 1;
    dp[2] = 2;
    //dp[2] 의 경우는 1+1과 2가 있다.
    for(int i=3;i<=11;i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int N;
        cin>>N;
        cout<<dp[N]<<'\n';   
    }
    return 0;
}