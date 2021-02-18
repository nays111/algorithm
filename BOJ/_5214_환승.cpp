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
int n,k,m;
vector<int> stationAndHyper[101002];
bool visit[101002];

void bfs(){
    queue<pair<int,int>> q;
    q.push(make_pair(1,1));//1번역출발, 역의개수:1
    visit[1] = true;

    while(!q.empty()){
        int cur = q.front().first;
        int count = q.front().second;
        q.pop();
        if(cur==n){
            //n번역 방문하면
            cout<<count/2+1;
            return;
        }
        for(int i=0;i<stationAndHyper[cur].size();i++){
            int next = stationAndHyper[cur][i];
            if(visit[next]==true){
                //방문한적이 있으면
                continue;
            }
            q.push(make_pair(next,count+1));
            visit[next]=true;
        }

    }
    cout<<-1;    
}




int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>k>>m;
    for(int i=1;i<=m;i++){
        for(int j=0;j<k;j++){
            int a;
            cin>>a;
            //1번역 100001(하이퍼튜브)와 연결
            //100001(하이퍼튜브)는 1번역과 연결
            stationAndHyper[a].push_back(i+100000);
            stationAndHyper[i+100000].push_back(a);
        }
    }
    bfs();
    return 0;
}