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

int tomato[1001][1001];
bool visit[1001][1001];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
queue<pair<int,int>> q;
int n,m;
void bfs(){
    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];

            if(nextY<0 || nextX<0 || nextY>=m || nextX>=n){
                continue;
            }

            if(tomato[nextY][nextX]==0){
                tomato[nextY][nextX] = tomato[curY][curX]+1;
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
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>tomato[i][j];
            if(tomato[i][j]==1){
                q.push(make_pair(i,j));
            }
        }
    }
    
    bfs();
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<tomato[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }



    int num=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(tomato[i][j]==0){ //0하나라도 남아있으면 모두 익지 못한 상태
                cout<<-1;
                return 0;
            }
            num=max(tomato[i][j],num);
        }
    }
    cout<<num-1;
    
    return 0;
}