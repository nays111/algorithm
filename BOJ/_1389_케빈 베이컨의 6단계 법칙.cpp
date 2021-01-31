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
int n,m;
vector<int> v[101];
int dist[101];
int bfs(int start){
    memset(dist,-1,sizeof(int)*(n+1));
    queue<int> q;
    int distance = 0;
    
    q.push(start);
    dist[start]=0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        distance=distance+dist[cur];
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i];
            if(dist[next]==-1){
                dist[next]=dist[cur]+1;
                q.push(next);
            }
        }

    }
    
    return distance;

}



int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int from,to;
        cin>>from>>to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    
    int answer;
    int min = 100000000;
    for(int i=1;i<=n;i++){
        int sum = bfs(i);
        if(sum<min){
            min=sum;
            answer = i;
        }
    }
    cout<<answer;
    
    

    return 0;
}