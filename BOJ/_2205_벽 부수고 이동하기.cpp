#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
using namespace std;
int n,m;
int arr[1001][1001];
bool visit[1001][1001][2];
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
int bfs(){
    queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(1, 1), make_pair(0, 0)));
	visit[0][0][1] = true;
    while(!q.empty()){
        int dist = q.front().first.first;
        int wall = q.front().first.second;
        int curY = q.front().second.first;
        int curX = q.front().second.second;
        q.pop();
        if(curY==(n-1) && curX==(m-1)){
            return dist;
        }
        for(int i=0;i<4;i++){
            int nextY = curY+dy[i];
            int nextX = curX+dx[i];
            if(nextY < 0 || nextX < 0 || nextY>=n || nextX >=m){
                continue;
            }
            if(wall==1 && arr[nextY][nextX]==1){// 벽부수는 경우
                visit[nextY][nextX][wall]=true;
                q.push(make_pair(make_pair(dist+1,wall-1),make_pair(nextY,nextX)));
            }else if(visit[nextY][nextX][wall]==false && arr[nextY][nextX]==0){
                visit[nextY][nextX][wall]=true;
                q.push(make_pair(make_pair(dist+1,wall),make_pair(nextY,nextX)));
            }
        }
    }
    return -1;
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

    cout<<bfs();
    
    return 0;
}