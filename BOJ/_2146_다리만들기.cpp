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
int arr[101][101];
int maps[101][101];//여기에는 연결요소 구분이 되있음 
bool visit[101][101];
int answer = 0;
int mini=100001;
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};

void dfs(int y,int x,int index){
    maps[y][x] = index;

    for(int i=0;i<4;i++){
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        if(nextY<0 || nextX<0 || nextY>=n || nextX>=n){
            continue;
        }

        if(arr[nextY][nextX]==1 && maps[nextY][nextX]==0){
            dfs(nextY,nextX,index);
        }
    }
}

int bfs(int count){
    queue<pair<pair<int,int>,int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(maps[i][j]==count){
                visit[i][j] =true;
                q.push(make_pair(make_pair(i,j),0));
            }
        }
    }

    
    
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            int curY = q.front().first.first;
            int curX = q.front().first.second;
            int distance = q.front().second;
            q.pop();


            for(int i=0;i<4;i++){
                int nextY = curY + dy[i];
                int nextX = curX + dx[i];

                if(nextY<0 || nextX<0 || nextY>=n || nextX>=n){
                    continue;
                }

                if(maps[nextY][nextX]==0 && visit[nextY][nextX]==false){
                    q.push(make_pair(make_pair(nextY,nextX),distance+1));
                    visit[nextY][nextX]=true;
                }

                if(maps[nextY][nextX]!=0 && maps[nextY][nextX]!=count){
                    return distance;
                }
            }
        }

    }
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
    int index = 1;
    //dfs로 연결요소 먼저 구분해주고
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1 && maps[i][j]==0){
                dfs(i,j,index);
                index++;
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<maps[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }

    int answer = 987654321;
    //bfs로 최소거리 찾기
    for(int i=1;i<index;i++){
        memset(visit,false,sizeof(visit));
        answer = min(answer,bfs(i));
    }
    cout<<answer;

    
    
    return 0;
}