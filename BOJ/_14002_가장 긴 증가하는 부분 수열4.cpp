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
int arr[1001];
int dp[1001];
int memo[1001];

void printArr(int p){
    if(p==-1){
        return;
    }
    printArr(memo[p]);
    cout<<arr[p]<<' ';
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    
    for(int i=0;i<N;i++){
        dp[i]=1;
        memo[i]=-1;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
                memo[i] = j;
            }
        }
    }
    int max=dp[0];
    int index = 0;
    for(int i=0;i<N;i++){
        if(max<dp[i]){
            max = dp[i];
            index = i; //최대인덱스
        }
    }
    //역추적을 해야함
    //하나의 값이 다른 값에 의해 바꾸는 경우가 많음 => 기록이 필요
    cout<<max<<'\n';
    printArr(index);
    
    return 0;
}