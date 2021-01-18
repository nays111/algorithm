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

int arr[27][27];
bool visit[27];
int r,c;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int answer = 0;

void dfs(int y,int x,int index){
    visit[arr[y][x]]=true;
    //cout<<index<<'\n';
    answer = max(answer,index);
    for(int i=0;i<4;i++){
        int nextY = y+dy[i];
        int nextX = x+dx[i];
        if(nextY<0 || nextX<0 || nextY>=r || nextX>=c){
            continue;
        }
        
        if(visit[arr[nextY][nextX]]==false){
            //cout<<nextY<<" "<<nextX<<'\n';
            dfs(nextY,nextX,index+1);
        }
    }
    visit[arr[y][x]]=false;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>r>>c;
    for(int i=0;i<r;i++){
        string str;
        cin>>str;
        for(int j=0;j<c;j++){
            arr[i][j]=str[j]-'A';
        }
    }
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout<<arr[i][j];
    //     }
    //     cout<<'\n';
    // }
    dfs(0,0,1);
    cout<<answer;
    return 0;

}