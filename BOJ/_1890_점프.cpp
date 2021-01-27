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
    long long dp[101][101];
    int arr[101][101];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (dp[i][j] == 0 || (i == n - 1 && j == n - 1)) {
                continue;
            }
            if(i+arr[i][j]<n){
                dp[i+arr[i][j]][j]+=dp[i][j];
            } 
            if(j+arr[i][j]<n){
                dp[i][j+arr[i][j]]+=dp[i][j];
            }
                         
                      
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    cout<<dp[n-1][n-1];
    
    
    
    return 0;
}