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
int r,c;
char arr[51][51];
bool visit[51][51];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int startPointY;
int startPointX;
int endPointY;
int endPointX;

vector<pair<int,int>> water;

int bfs(int y,int x){

    //초기값 세팅
    queue<pair<int,pair<int,int>>> q;
    queue<pair<int,int>> waterQ;
    q.push(make_pair(0,make_pair(y,x)));
    visit[y][x]=true;


    for(int i=0;i<water.size();i++){
        waterQ.push(make_pair(water[i].first,water[i].second));
    }

    while(!q.empty()){
        //물먼저
        int waterQSize = waterQ.size();
        for(int i=0;i<waterQSize;i++){
            int waterY = waterQ.front().first;
            int waterX = waterQ.front().second;
            waterQ.pop();
            for(int j=0;j<4;j++){
                int nextWaterY = waterY + dy[j];
                int nextWaterX = waterX + dx[j];
                if(nextWaterX<0 || nextWaterY<0 || nextWaterY>=r || nextWaterX>=c){
                    continue;
                }
                if(arr[nextWaterY][nextWaterX]=='.'){
                    arr[nextWaterY][nextWaterX]='*';
                    waterQ.push(make_pair(nextWaterY,nextWaterX));
                }

            }
        }
        //고슴도치
        int qSize = q.size();
        for(int i=0;i<qSize;i++){
            int result = q.front().first;
            int curY = q.front().second.first;
            int curX = q.front().second.second;
            q.pop();

            if(curY==endPointY && curX==endPointX){
                
                return result;
            }

            for(int j=0;j<4;j++){
                int nextY = curY + dy[j];
                int nextX = curX + dx[j];
                
                if(nextX<0 || nextY<0 || nextY>=r || nextX>=c){
                    continue;
                }
                if(visit[nextY][nextX]==false && (arr[nextY][nextX]=='.'||arr[nextY][nextX]=='D')){
                    visit[nextY][nextX]=true;
                    
                    q.push(make_pair(result+1,make_pair(nextY,nextX)));
                }
                
            }

        }


    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout<<arr[i][j];
    //     }
    //     cout<<'\n';
    // }
    // cout<<'\n';

    // }
    }
    return -1;
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
            arr[i][j]=str[j];
            if(arr[i][j]=='D'){
                endPointY=i;
                endPointX=j;
                
            }else if(arr[i][j]=='S'){
                startPointY=i;
                startPointX=j;
            }else if(arr[i][j]=='*'){
                water.push_back(make_pair(i,j));
            }
        }
    }
    //cout<<endPointY<<" "<<endPointX<<'\n';

    
    int a = bfs(startPointY,startPointX);
    
    if(a==-1){
        cout<<"KAKTUS";
    }else{
        cout<<a;
    }
    
    return 0;

}