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
int arr[501][501];
bool visit[501][501];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int n,m;
int answer;

//깊이가 4일때까지만 돌면댐
//모양 여러가지 중 가장 큰 것
void dfs(int y,int x,int depth,int sum){
    visit[y][x] = true;
    if(depth==3){
        answer = max(answer,sum);
        return; // 깊이 4만큼 돌면 더 할필요 없음
    }

    for(int i=0;i<4;i++){
        int nextY = y+dy[i];
        int nextX = x+dx[i];
        if(nextY<0 || nextX<0 || nextY>=n || nextX>=m){
            continue;
        }
        if(visit[nextY][nextX]==false){
            dfs(nextY,nextX,depth+1,sum+arr[nextY][nextX]);
            visit[nextY][nextX]=false;
        }
    }

}
//예외인 한 모양이 있는데 이거는 따로 처리해줘야함
//한 모양으로 4가지 경우 나옴
void pattern1(int y,int x){
    if(y-1>=0 && x+2<m){
        int sum = arr[y][x] + arr[y][x+1] + arr[y][x+2] + arr[y-1][x+1];
        answer = max(answer,sum);
    }
}
void pattern2(int y,int x){
    if(y+1<n && x+2<m){
        int sum = arr[y][x] + arr[y][x+1] + arr[y+1][x+1] + arr[y][x+2];
        answer = max(answer,sum);
    }
}
void pattern3(int y,int x){
    if(y+2<n && x+1<m){
        int sum = arr[y][x] + arr[y+1][x] + arr[y+2][x] + arr[y+1][x+1];
        answer = max(answer,sum);
    }
}

void pattern4(int y,int x){
    if(y-1>=0 && x+1<m && y+1<n){
        int sum = arr[y][x]+arr[y-1][x+1]+arr[y][x+1]+arr[y+1][x+1];
        answer = max(answer,sum);
    }
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

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            memset(visit,false,sizeof(visit));
            dfs(i,j,0,arr[i][j]);
            pattern1(i,j);
            pattern2(i,j);
            pattern3(i,j);
            pattern4(i,j);
        }
    }

    cout<<answer;
    return 0;
}