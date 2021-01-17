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
int n,m,k;
bool check[101][101];
int arr[101][101];
// vector<int> v[101];
// queue<int> q;
queue<pair<int,int>> q;
int nx[] = {1,-1,0,0};
int ny[] = {0,0,1,-1};

int bfs(int y,int x){
    q.push(make_pair(y,x));
    check[y][x]=true;
    int trashWeight = arr[y][x];

    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int newY = curY + ny[i];
            int newX = curX + nx[i];
            
            if(newX<1 || newY<1 ||newX>m || newY>n){
                continue;
            }
            if(check[newY][newX]==false && arr[newY][newX]>=1){
                q.push(make_pair(newY,newX));
                check[newY][newX]=true;
                trashWeight=trashWeight+arr[newY][newX];
            }
        }
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            check[i][j]=false;
        }
    }

    return trashWeight;
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        int r,c;
        cin>>r>>c;
        arr[r][c]++;
    }
    int max = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(max<bfs(i,j) && arr[i][j]>=1){
                max = bfs(i,j);
            }
        }
    }
    cout<<max;
    
    
    

    return 0;
}