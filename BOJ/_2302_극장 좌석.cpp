#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
using namespace std;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int dp[41];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    int start = 0;
    int answer = 1;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        answer=answer*dp[a-start-1];
        start=a;
        //cout<<answer<<'\n';
    }
    answer = answer * dp[n-start];
    cout<<answer;




    return 0;

}