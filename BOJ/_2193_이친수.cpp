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
    long long dp0[91];
    long long dp1[91];
    int N;
    cin>>N;
    dp0[1]=0;
    dp1[1]=1;
    for(int i=2;i<=N;i++){
        dp0[i]=dp0[i-1]+dp1[i-1];
        dp1[i]=dp0[i-1];
    }
    cout<<dp0[N]+dp1[N];
    return 0;
}