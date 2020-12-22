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
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int dp[N];
    int max = 0;
    for(int i=0;i<N;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                //arr[i]가 기준이고 그 전에꺼 차례대로 검사
                if(dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
        }
        if(dp[i]>max){
            max = dp[i];
        }
    }
    cout<<max;
    return 0;
}