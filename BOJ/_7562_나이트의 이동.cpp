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

bool visit[301][301];

int dx[]={2,2,1,1,-2,-2,-1,-1};
int dy[]={1,-1,2,-2,1,-1,2,-2};
int bfs(int size,int y,int x,int targetY,int targetX){
    queue<pair<int,pair<int,int>>> q;
    
    q.push(make_pair(0,make_pair(y,x)));
    visit[y][x]=true;
    while(!q.empty()){
        int count = q.front().first;
        int curY = q.front().second.first;
        int curX = q.front().second.second;
        if(curY==targetY && curX==targetX){
            return count;
        }
        q.pop();
        for(int i=0;i<8;i++){
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if(nextY<0 || nextX<0 ||nextY>=size ||nextX>=size){
                continue;
            }
            if(visit[nextY][nextX]==false){
                visit[nextY][nextX]=true;
                q.push(make_pair(count+1,make_pair(nextY,nextX)));
            }


        }
    }
    return -1;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        memset(visit,false,sizeof(visit));
        int l,startY,startX, targetY, targetX;
        cin>>l>>startY>>startX>>targetY>>targetX;
        int num = bfs(l,startY,startX,targetY,targetX);
        cout<<num<<'\n';
    }
    
    return 0;

}