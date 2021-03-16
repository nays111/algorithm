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
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int arr[3][10001];
        for(int j=0;j<n;j++){
            cin>>arr[0][j];
        }
        for(int j=0;j<n;j++){
            cin>>arr[1][j];
        }
        int dp[3][100001];
        dp[0][0]=arr[0][0];
        dp[1][0]=arr[1][0];
        int answer = 0;
        for(int j=1;j<n;j++){
            dp[0][j]=max(dp[0][j-1],dp[1][j-1]+arr[0][j]);
            dp[1][j]=max(dp[1][j-1],dp[0][j-1]+arr[1][j]);
            answer = max(answer,max(dp[0][j],dp[1][j]));
        }

        cout<<answer<<'\n';
    }

    return 0;
    
}