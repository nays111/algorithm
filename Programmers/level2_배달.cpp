#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<vector<pair<int,int>>> v(N+1);
    for(int i=0;i<road.size();i++){
        v[road[i][0]].push_back(make_pair(road[i][1],road[i][2]));
        v[road[i][1]].push_back(make_pair(road[i][0],road[i][2]));
    }

    pq.push(make_pair(0,1));
    int dist[51]={0,};
    dist[1]=0;
    //v : 인덱스(first) + 거리(second)
    //pq : 거리(first) + 인덱스(second)
    //거리가 가까운거부터 가야함
    //pq 는 dist가 작은게 제일 top
    while(!pq.empty()){//pq : dist가 짧은 순으로 정렬
        int curLoc = pq.top().second;
        int curDist = pq.top().first;
        
        pq.pop();

        for(int i=0;i<v[curLoc].size();i++){
            int nextLoc = v[curLoc][i].first;
            int nextDist = curDist + v[curLoc][i].second;

            if(dist[nextLoc]==0){
                dist[nextLoc]=nextDist;
                pq.push(make_pair(nextDist,nextLoc));
                continue;
            }
            if(dist[nextLoc]>nextDist){
                dist[nextLoc]=nextDist;
                pq.push(make_pair(nextDist,nextLoc));
                continue;
            }
              
        }
    }
    dist[1]=0;
    
    for(int i=1;i<=N;i++){
        //cout<<dist[i];
        if(dist[i]<=K){
            answer++;
        }
    }
    

    return answer;
}