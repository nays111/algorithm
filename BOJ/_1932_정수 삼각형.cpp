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
    int A;
    int result=0;// 초기값을 넣어놔아야 dp 할때 비교 가능
    int arr[502][502]; //원본 삼각형
    int dp[502][502]; // 경로값을 입력해두는 삼각형
    cin>>A;
    for(int i=1;i<=A;i++){
        for(int j=1;j<=i;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=A;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=arr[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
        }
        //dp[i-1],,, 이 0인 공간이 있을 수도 있음
    }

    for(int i=1;i<=A;i++){
        result = max(result,dp[A][i]); //최종 경로값들은 맨 아랫줄에 저장되었음
    }//여기서도 dp (이전에 저장해놓은 result값을 계속 사용)
    cout<<result;
    

    return 0;

}