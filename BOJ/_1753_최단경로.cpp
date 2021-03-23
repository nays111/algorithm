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
#define INF 987654321
using namespace std;

//가중치 주어졌으니깐 다익스트라로
int n,e,k;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>e>>k;
    vector<pair<int,int>> v[20001];
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));//first -> index, second ->  dist
    }
    vector<int> dist(n+1,INF);
    dist[k]=0;

    //가장 짧은게 우선순위
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //first -> dist, second -> index
    //priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,k));
    while(!pq.empty()){
        int curLoc = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();
        if(curDist > dist[curLoc]){
            continue;
        }
        for(int i=0;i<v[curLoc].size();i++){
            int nextLoc = v[curLoc][i].first;
            int nextDist = curDist + v[curLoc][i].second;

            if(nextDist < dist[nextLoc]){
                pq.push(make_pair(nextDist,nextLoc));
                dist[nextLoc] = nextDist;
            }
        }

    }

    for(int i=1;i<=n;i++){
        if(dist[i]==INF){
            cout<<"INF"<<'\n';
        }else{
            cout<<dist[i]<<'\n';
        }
    }
    

    return 0;
}