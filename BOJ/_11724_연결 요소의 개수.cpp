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
bool check[1001];
vector<int> arr[1001]; //인접리스트
int n,m;
void dfs(int curr){
    check[curr]=true;//현재 위치 방문
    for(int i=0;i<arr[curr].size();i++){ //arr[1] = 2,5
        int next = arr[curr][i];
        if(check[next]==false){
            //방문안했더라면 dfs
            dfs(next);
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        //방향 없는 그래프 -> 쌍방향
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    // dfs(1);
    // dfs(2);
    // dfs(3);
    int answer = 0;
    for(int i=1;i<=n;i++){
        if(check[i]==false){
            //방문안했으면 dfs를 돈다
            dfs(i);
            //한번 돌면 하나의 연결요소 내를 전부 돈 것
            answer++;
        }
    }
    cout<<answer;
    
    

    return 0;
}