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
int arr[17][17];
int dy[]={0,1,1};
int dx[]={1,0,1};
int answer = 0;

void bfs(){
    queue<pair<pair<int,int>,int>> q;
    //방향 1 : 가로, 2: 세로, 3: 대각선
    //맨처음엔 가로
    q.push(make_pair(make_pair(0,1),0));

    while(!q.empty()){
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        int dir = q.front().second;
        q.pop();
        
        //최종 목적지에 도달할때마다 경우의 수 1증가
        if(curY==n-1 && curX ==n-1){
            answer++;
            continue;
        }

        ///대각선으로 갈 때는 옆쪽이랑 아래쪽도 0이어야함!

        //가로로 갈려는 경우
        if(dir==0){
            //또 가로로 가는 경우
            int nextY = curY + dy[0];
            int nextX = curX + dx[0];
            if(nextY>=0 && nextX>=0 && nextY<n && nextX<n){
                if(arr[nextY][nextX]==0){
                    q.push(make_pair(make_pair(nextY,nextX),0));
                }
            }
            
            //대각선으로 가는 경우
            nextY = curY+dy[2];
            nextX = curX+dx[2];
            if(nextY>=0 && nextX>=0 && nextY<n && nextX<n){
                if(arr[nextY][nextX]==0 && arr[nextY][nextX-1]==0 && arr[nextY-1][nextX]==0){
                    q.push(make_pair(make_pair(nextY,nextX),2));
                }
            }
        }else if(dir==1){//세로로 온 경우 -> 세로나 대각선으로 밖에 못감
            int nextY = curY + dy[1];
            int nextX = curX + dx[1];
            if(nextY>=0 && nextX>=0 && nextY<n && nextX<n){
                if(arr[nextY][nextX]==0){
                    q.push(make_pair(make_pair(nextY,nextX),1));
                }
            }
            //대각선으로 가는 경우
            nextY = curY+dy[2];
            nextX = curX+dx[2];
            if(nextY>=0 && nextX>=0 && nextY<n && nextX<n){
                if(arr[nextY][nextX]==0 && arr[nextY][nextX-1]==0 && arr[nextY-1][nextX]==0){
                    q.push(make_pair(make_pair(nextY,nextX),2));
                }
            }
        }else if(dir==2){//대각선으로 온 경우 -> 이때는 아무 방향이나 갈 수 있음
            
            int nextY = curY + dy[0];
            int nextX = curX + dx[0]; 
            if(nextY>=0 && nextX>=0 && nextY<n && nextX<n){
                if(arr[nextY][nextX]==0){
                    q.push(make_pair(make_pair(nextY,nextX),0));
                }
            }
            
            nextY = curY + dy[1];
            nextX = curX + dx[1];
            if(nextY>=0 && nextX>=0 && nextY<n && nextX<n){
                if(arr[nextY][nextX]==0){
                    q.push(make_pair(make_pair(nextY,nextX),1));
                }
            }
            
            //대각선으로 가는 경우
            nextY = curY+dy[2];
            nextX = curX+dx[2];
            if(nextY>=0 && nextX>=0 && nextY<n && nextX<n){
                if(arr[nextY][nextX]==0 && arr[nextY][nextX-1]==0 && arr[nextY-1][nextX]==0){
                    q.push(make_pair(make_pair(nextY,nextX),2));
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
    bfs();
    cout<<answer;

    return 0;
}