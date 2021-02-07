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
bool visit[101];
int answer = 0;

void bfs(int start){
    queue<int> q;
    q.push(start);
    visit[start] = true;
    //스타트와 연결된 행렬들을 탐색
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i];
            if(visit[next]==false){
                q.push(next);
                answer++;
                visit[next] = true;
            }
        }

    }

}

//1. 인접행렬로 받는다.
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1);
    cout<<answer;
    return 0;
}