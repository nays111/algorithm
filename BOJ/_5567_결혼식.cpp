#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
using namespace std;
int n,m;
vector<int> v[501];
bool visit[501];
queue<int> q;
int answer = 0;
void bfs(int index){
    visit[index]=true;
    q.push(index);

    for(int i=0;i<=v[index].size();i++){//친구의 친구니깐 처음 친구 리스트의 수만큼만 루프
        int cur = q.front();
        q.pop();
        for(int j=0;j<v[cur].size();j++){
            int next = v[cur][j];
            //cout<<"dd"<<next<<'\n';
            if(visit[next]==false){
                visit[next]=true;
                //cout<<"aa"<<next<<'\n';
                q.push(next);
                answer++;
            }
        }
    }
}

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