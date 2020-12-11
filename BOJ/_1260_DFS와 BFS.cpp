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
int N;
int M;
int V;
int arr[1001][1001]={0};
int visited[1001]={0};
void dfs(int n){
    cout<<n<<" ";
    visited[n] = 1;
    for(int i=1;i<=N;i++){
        if(arr[n][i]==1 && !visited[i]){
            dfs(i);
        }
    }
    

}
void bfs(int n){
    queue<int> q;
    q.push(n);
    visited[n]=1;
    while(!q.empty()){
        n=q.front();
        q.pop();
        cout<<n<<" ";
        for(int i=1;i<=N;i++){
            if(arr[n][i]==1&&!visited[i]){
                visited[i] = 1;//방문했다고 표시
                q.push(i);//방문한 노드 삽입
            }
        }
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>N>>M>>V;
    int x,y;
    for(int i=0;i<M;i++){
        cin>>x>>y;
        arr[x][y]=arr[y][x]=1;// 양방향이므로 같다.
    }
    dfs(V);
    //방문한 배열을 초기화 해줘야함
    cout<<endl;
    memset(visited, 0, sizeof(visited));

    bfs(V);

    return 0;
}