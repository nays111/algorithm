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
int arr[51][51];
bool visit[51][51];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int m,n,k;
void init(){
    for(int i=0;i<51;i++){
        for(int j=0;j<51;j++){
            arr[i][j]=0;
            visit[i][j]=false;
        }
    }
}
void dfs(int curY,int curX){
    visit[curY][curX]=true;
    for(int i=0;i<4;i++){
        int nextY = curY+dy[i];
        int nextX = curX+dx[i];
        if(nextY<0 || nextX<0 || nextY>=n || nextX>=m){
            continue;
        }
        if(arr[nextY][nextX]==1 && visit[nextY][nextX]==false){
            
            dfs(nextY,nextX);
        }
    }

}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>m>>n>>k; //m은 가로길이, n은 세로길이
        for(int j=0;j<k;j++){
            int x,y;//x y순
            cin>>x>>y;
            arr[y][x]=1;
        } 
        int answer = 0;
        for(int j=0;j<n;j++){
            for(int l=0;l<m;l++){
                if(arr[j][l]==1 && visit[j][l]==false){
                    answer++;
                    dfs(j,l);
                }
            }
        }
        cout<<answer<<'\n';
        init();
    }
    
    return 0;

}