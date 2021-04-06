#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    bool visit[200001];
    vector<vector<int>> v(200001);
    vector<int> dist(200001);
    
    
    for(int i=0;i<edge.size();i++){
        int from = edge[i][0];
        int to = edge[i][1];
        v[from].push_back(to);
        v[to].push_back(from);
    }
    queue<pair<int,int>> q;
    q.push({1,0});//출발위치 + 처음 거리(0)
    visit[1]=true;
    while(!q.empty()){
        int cur = q.front().first;
        int curDist = q.front().second;
        dist[cur]=curDist;
        q.pop();
        
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i];
            if(visit[next]==false){
                int nextDist = curDist + 1;
                q.push({next,nextDist});
                visit[next]=true;
                
            }
        }
    }
    
    int maxDist=0;
    for(int i=1;i<=n;i++){
        maxDist = max(maxDist,dist[i]);
    }
    for(int i=1;i<=n;i++){
        if(maxDist==dist[i]){
            answer++;
        }
    }
    
    
    
    return answer;
}