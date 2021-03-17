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
int n,m;
int arr[501][501];
int dy[]={0,0,-1,1};
int dx[]={1,-1,0,0};
bool visit[501][501];

int answer = 0;
int dp[501][501]={0,};


int dfs(int y,int x){
    
    if(y==n-1 && x==m-1){
        return 1;
    }
    if(visit[y][x]==true){
        return dp[y][x];
    }
    visit[y][x]=true;
    for(int i=0;i<4;i++){
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        if(nextY<0 || nextX<0 || nextY>=n || nextX>=m){
            continue;
        }
        if(arr[nextY][nextX]<arr[y][x]){
            dp[y][x]+=dfs(nextY,nextX);
        }
    }
    return dp[y][x];
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<dfs(0,0);

    return 0;
}