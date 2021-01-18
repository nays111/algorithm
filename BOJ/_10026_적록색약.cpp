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
int n;
char rgb[101][101];
bool visit[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int countRG = 0;
int countNoRG = 0;

void dfs(int y,int x){
    visit[y][x]=true;
    char target = rgb[y][x];
    //cout<<target<<'\n';
    
    for(int i=0;i<4;i++){
        int nextY = y+dy[i];
        int nextX = x+dx[i];
        if(nextY<0||nextX<0||nextY>=n||nextX>=n){
            continue;
        }
        if(visit[nextY][nextX]==false && rgb[nextY][nextX]==target){
            dfs(nextY,nextX);
        }   
    }
}



void initVisit(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visit[i][j]=false;
        }
    }
}
void GreenToRed(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(rgb[i][j]=='G'){
                rgb[i][j]='R';
            }
        }
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<n;j++){
            rgb[i][j]=str[j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]==false){
                dfs(i,j);
                countRG++;
            }
        }
    }
    initVisit();
    GreenToRed();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]==false){
                dfs(i,j);
                countNoRG++;
            }
        }
    }

    cout<<countRG<<" "<<countNoRG;
    

    return 0;
}