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
        int dp0[40]; //0이 출력되는 횟수
        int dp1[40]; //1이 출력되는 횟수
        dp0[0]=1;
        dp0[1]=0;
        dp1[0]=0;
        dp1[1]=1;
        for(int j=2;j<=n;j++){
            dp0[j]=dp0[j-1]+dp0[j-2];
            dp1[j]=dp1[j-1]+dp1[j-2];
        }
        cout<<dp0[n]<<" "<<dp1[n]<<'\n';
    }
    return 0;
}