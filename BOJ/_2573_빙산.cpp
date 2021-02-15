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
int arr[301][301];
bool visit[301][301];
bool meltVisit[301][301];
int temp[301][301];
int n,m;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void dfs(int y,int x){
    visit[y][x] = true;

    for(int i=0;i<4;i++){
        int nextY = dy[i] + y;
        int nextX = dx[i] + x;
        if(nextY<0 || nextX<0 || nextY>=n || nextX>=m){
            continue;
        }
        if(visit[nextY][nextX]==false && arr[nextY][nextX]>0){
            dfs(nextY,nextX);
        }
    }
}
bool allZero(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]>0){
                //cout<<"false"<<'\n';
                return false;
            }
        }
    }
    //cout<<"True"<<'\n';
    return true;
}

int melt(int y,int x){
    int count = 0;
    for(int i=0;i<4;i++){
        int nextY = dy[i] + y;
        int nextX = dx[i] + x;
        if(nextY<0 || nextX<0 || nextY>=n || nextX>=m){
            continue;
        }
        if(temp[nextY][nextX]<=0){
            count++;
        }
    }
    return count;
}



int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int answer = 0;
    while(allZero()!=true){
        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visit[i][j]==false && arr[i][j]>0){
                    dfs(i,j);
                    count++;
                    if(count>1){
                        cout<<answer;
                        return 0;
                    }
                }
            }
        }
        //cout<<count;
        
        answer++;


        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp[i][j] = arr[i][j];
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]>0){
                    int count = melt(i,j);
                    arr[i][j] = temp[i][j]-count;
                }
            }
        }
        memset(visit,false,sizeof(visit));
    }
    //cout<<0;
    
    
    
    return 0;
}