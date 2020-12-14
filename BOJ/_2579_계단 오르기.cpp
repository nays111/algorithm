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
int dp[300];
int arr[300];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[0]+arr[1]);//한번 점프할때 두번 점프할때 중 큰거
    dp[2]=max(arr[0]+arr[2],arr[1]+arr[2]);
    for(int i=3;i<N;i++){
        dp[i] = max(dp[i-2]+arr[i],dp[i-3]+arr[i-1]+arr[i]);
    }
    cout<<dp[N-1];


    return 0;

}