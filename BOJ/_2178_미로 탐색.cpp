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
int arr[101][101];
int dist[101][101];
bool visit[101][101];
//최단 경로는 주로 BFS를 사용한다고 함
queue<pair<int,int>> q;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(int y,int x){
    q.push(make_pair(y,x));
    visit[y][x] = true;
    dist[y][x] = 1;

    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        if(curY==n-1 && curX==m-1){
            cout<<dist[curY][curX];
            return;
        }

        for(int i=0;i<4;i++){
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            

            if(nextY<0 || nextX<0 || nextY>=n || nextX>=m){
                continue;
            }
            if(visit[nextY][nextX]==false && arr[nextY][nextX]==1){
                dist[nextY][nextX]= dist[curY][curX] + 1;
                visit[nextY][nextX] = true;
                q.push(make_pair(nextY,nextX));
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
        string str;
        cin>>str;
        for(int j=0;j<m;j++){
            arr[i][j] = str[j]-'0';
        }
    }
    bfs(0,0);
    

    return 0;
}