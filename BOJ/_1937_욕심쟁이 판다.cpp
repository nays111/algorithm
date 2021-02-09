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
int n;
int arr[501][501];
int dp[501][501];
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};


int dfs(int y,int x){
    
    if(dp[y][x]) //dp에값이 있으면 전에 가장 긴 거리를 구했다.
        return dp[y][x];
    dp[y][x] = 1; //전에 안갔으면 1로 설정

    for(int i=0;i<4;i++){
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        if(nextY<0 || nextX<0 || nextY>=n || nextX>=n){
                continue;
        }
        if(arr[y][x] < arr[nextY][nextX]){
            dp[y][x] = max(dp[y][x],dfs(nextY,nextX)+1);
        }
    }
    return dp[y][x];

}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            answer = max(dfs(i,j),answer);
        }
    }
    cout<<answer;

   
    
    return 0;
}