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
int m,n,k;
int arr[101][101];
bool visit[101][101];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int counts = 0;
//0인 구역을 찾아내야함(연결요소) + 각 구역의 사이즈
void dfs(int y,int x){
    visit[y][x]=true;
    counts++;

    for(int i=0;i<4;i++){
        int newY = y + dy[i];
        int newX = x + dx[i];
        if(newX<0 || newY<0 || newX>=n || newY>=m){
            continue;
        }
        if(visit[newY][newX]==false && arr[newY][newX]==0){
            dfs(newY,newX);
        }

    }


}



int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>m>>n>>k;
    for(int i=0;i<k;i++){
        int startX,startY,endX,endY;
        cin>>startX>>startY>>endX>>endY;
        for(int j=endX-1;j>=startX;j--){
            for(int l=m-endY;l<m-startY;l++){
                arr[l][j] = 1;
            }
        }
    }
    int totalCount = 0;
    vector<int> v;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0 && visit[i][j]==false){
                counts = 0;
                dfs(i,j);
                v.push_back(counts);
                totalCount++;
            }
        }
    }
    sort(v.begin(),v.end());
    cout<<totalCount<<'\n';
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}