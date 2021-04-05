#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;



bool visit[26][26];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1 ,-1, 0};
int total = 987654321;

void dfs(vector<vector<int>> &board,int y,int x,int n,int m,int cost,int direction){
    
    if(y==n-1 && x==m-1){
        //cout<<cost;
        total = min(total,cost);
        return;
    }else{
        for(int i=0;i<4;i++){
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            int nextDirection = i;
            if(nextY <0 || nextX < 0 || nextY >=n || nextX >=m){
                continue;
            }
            if(board[nextY][nextX]==0 && visit[nextY][nextX]==false){
                if(direction!=nextDirection){
                    visit[nextY][nextX] = true;
                    int temp = 0;
                    if(x==0 && y==0){
                        temp = 100;
                    }else{
                        temp = 600;
                    }
                    dfs(board,nextY,nextX,n,m,cost+temp,nextDirection);
                    visit[nextY][nextX] = false;
                }else if(direction == nextDirection){
                    
                    visit[nextY][nextX] = true;
                    dfs(board,nextY,nextX,n,m,cost+100,nextDirection);
                    visit[nextY][nextX] = false;
                    
                }
            }
        }
    }
}



int solution(vector<vector<int>> board) {
    int answer = 987654321;
    int n = board.size();
    int m = 0;
    for(int i=0;i<board.size();i++){
        m = board[i].size();
    }
    visit[0][0]=true;
    //dfs(board,0,0,n,m,0,5);
    //dfs 로 하니깐 시간 초과
    
    //answer = total;
    
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{0,0},{0,0}});//y,x,방향,비용
    board[0][0] = 1; //다시 (0,0) 방문 안하게끔
    
    
    while(!q.empty()){
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        int curDir = q.front().second.first;
        int curCost = q.front().second.second;
        q.pop();
        if(curY == n-1 && curX == m-1){
            answer = min(answer,curCost);
        }
        for(int i=0;i<4;i++){
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            int nextDir = i;
            int nextCost;
            if(nextDir==curDir){
                nextCost = curCost + 100;
            }else if(nextDir!=curDir){
                if(curY==0 && curX==0){
                    nextCost = curCost + 100; //시작할 땐 방향 상관없이 100
                }else{
                    nextCost = curCost + 600;
                }
            }
            if(nextY <0 || nextX <0 || nextY>=n || nextX>=m){ // map 밖으로 못감
                continue;
            }
            if(board[nextY][nextX]==1){ //벽은 못감
                continue;
            }
            if(board[nextY][nextX]==0 || board[nextY][nextX] >= nextCost){
                q.push({{nextY,nextX},{nextDir,nextCost}});
                board[nextY][nextX] = nextCost;
            }
        }
    }
    
    return answer;
}