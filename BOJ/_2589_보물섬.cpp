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
char arr[51][51];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int distances[51][51];
int bfs(int y,int x){
    //queue<pair<pair<int,int>,int>> q;
    memset(distances,0,sizeof(distances));
    queue<pair<int,int>> q;
    //bool visited[51][51];
    // q.push(make_pair(make_pair(y,x),1));
    // visited[y][x]=true;
    // int maxDistance=0;
    q.push(make_pair(y,x));
    distances[y][x]=1;
    int maxDistance=0;
    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        //int distance = q.front().second;
        //maxDistance = max(distance,maxDistance);
        
        q.pop();
        for(int i=0;i<4;i++){
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            maxDistance = max(maxDistance,distances[curY][curX]);
            if(nextY <0 || nextX<0 || nextY>=n || nextX>=m){
                continue;
            }
            if(distances[nextY][nextX]==0 && arr[nextY][nextX]=='L'){
                q.push(make_pair(nextY,nextX));
                distances[nextY][nextX] = distances[curY][curX]+1;
            }
        }
    }
    return maxDistance-1;
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
    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='L'){
                int length = bfs(i,j);
                answer = max(length,answer);        
            }
        }
    }  
    cout<<answer;

    return 0;
}