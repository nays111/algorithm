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
int dz[]={0,0,0,0,1,-1};
int dy[]={0,0,1,-1,0,0};
int dx[]={1,-1,0,0,0,0};
int arr[101][101][101];
queue<pair<int,pair<int,int>>> q;
int m,n,h;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>m>>n>>h;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin>>arr[i][j][k];
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(arr[i][j][k]==1){
                    q.push(make_pair(i,make_pair(j,k)));
                }
            }
        }
    }
    while(!q.empty()){
        int curZ = q.front().first;
        int curY = q.front().second.first;
        int curX = q.front().second.second;
        q.pop();

        for(int i=0;i<6;i++){
            int nextZ = curZ + dz[i];
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if(nextZ < 0 || nextY < 0|| nextX <0 || nextZ >=h || nextY>=n || nextX>=m){
                continue;
            }
            if(arr[nextZ][nextY][nextX]==0){
                q.push(make_pair(nextZ,make_pair(nextY,nextX)));
                arr[nextZ][nextY][nextX]=arr[curZ][curY][curX]+1;
            }
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(arr[i][j][k]==0){
                    cout<<-1;
                    return 0;
                }
            }
        }
    }
    int answer = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                answer = max(answer,arr[i][j][k]);
            }
        }
    }
    cout<<answer-1;
    

    

    return 0;
}