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
int r,c;
char arr[251][251];
bool visit[251][251];
int wolf=0;
int sheep = 0;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };



void bfs(int y,int x){
    queue<pair<int,int>> q;
    int wolfTemp = 0;
    int sheepTemp = 0;
    q.push(make_pair(y,x));
    visit[y][x] = true;
    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        // if(arr[curY][curX]=='v'){
        //     wolfTemp++;
        // }
        // if(arr[curY][curX]=='o'){
        //     sheepTemp++;
        // }
        for(int i=0;i<4;i++){
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if(nextY<=0 || nextX<=0 || nextY>r || nextX>c){
                continue;
            }

            if(visit[nextY][nextX]==false && arr[nextY][nextX]!='#'){
                        if(arr[nextY][nextX]=='v'){
            wolfTemp++;
        }
        if(arr[nextY][nextX]=='o'){
            sheepTemp++;
        }
                visit[nextY][nextX]=true;
                q.push(make_pair(nextY,nextX));
            }          
        }
    }
    if(wolfTemp>=sheepTemp){
        wolf = wolf + wolfTemp;
    }else{
        sheep = sheep + sheepTemp;
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]!='#' && visit[i][j]==false){
                bfs(i,j);
            }
        }
    }
    cout<<sheep<<" "<<wolf;

    return 0;

}


