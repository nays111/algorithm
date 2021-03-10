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
int arr[9][9];
int virus[9][9];
int answer = 0;
int temp[9][9];
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};

void copyArrToTemp(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp[i][j]=arr[i][j];
        }
    }
}

void copyTempToVirus(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            virus[i][j]=temp[i][j];
        }
    }
}
void bfs(){

    copyTempToVirus();//벽을 세운 상태로 바이러스 확산을 계산해야함

    queue<pair<int,int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==2){//바이러스 시작점 -> 2
                q.push(make_pair(i,j));
            }
        }
    }

    while(!q.empty()){ //바이러스 퍼지는 과정
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if(nextY<0 || nextX<0 || nextY>=n || nextX>=m){
                continue;
            }
            if(virus[nextY][nextX]==0){
                virus[nextY][nextX]=2;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
    //안전한 영역의 개수
    int safe = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(virus[i][j]==0){
                safe++;
            }
        }
    }
    answer = max(answer,safe);

}

void dfs(int cnt){
    if(cnt==3){
        bfs();
        return;
    }else{
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j]==0){
                    temp[i][j]=1;//벽세우기
                    dfs(cnt+1);
                    temp[i][j]=0;//벽허물기     
                }
            }
        }
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
            if(arr[i][j]==0){//비어있으면 여기 벽을 놓을 수 있다는 거
                copyArrToTemp();
                temp[i][j]=1; // 벽을 하나 두고
                dfs(1);
                temp[i][j]=0; //벽 허뭄
            }
        }
    }

    cout<<answer;
    return 0;
}