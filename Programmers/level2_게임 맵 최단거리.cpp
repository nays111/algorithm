#include<vector>
#include<iostream>

#include <queue>
int dy[]={0,0,1,-1};
int dx[]={-1,1,0,0};
bool arr[101][101];

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int m = 0;
    for(int i=0;i<maps.size();i++){
        m = maps[i].size();
    }
    int n = maps.size();
    
    
    
    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(0,0),1));
    arr[0][0] = true;
    while(!q.empty()){
        int startY = q.front().first.first;
        int startX = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        if(startY == n-1 && startX == m-1){
            answer = dist;
            return answer;
        }
        for(int i=0;i<4;i++){
            int nextY = startY + dy[i];
            int nextX = startX + dx[i];
            int nextDist = dist + 1;
            
            if(nextY < 0 || nextX < 0 || nextY >=n || nextX >=m){
                continue;
            }
            
            
            if(arr[nextY][nextX]==false && maps[nextY][nextX]==1){
                q.push(make_pair(make_pair(nextY,nextX),nextDist));
                arr[nextY][nextX]=true;
            }
        }
    }
    
    
    
    
    return answer;
}