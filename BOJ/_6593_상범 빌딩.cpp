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
int dx[]={0,0,0,0,1,-1};
int dy[]={0,0,1,-1,0,0};
int dz[]={1,-1,0,0,0,0};

int arr[31][31][31];
bool visit[31][31][31];
int dist[31][31][31];


int l,r,c;
int startingPointZ,startingPointY,startingPointX;
int endPointZ, endPointY, endPointX;

queue<pair<pair<int,int>,int>> q;

void bfs(int z,int y,int x){
    q.push(make_pair(make_pair(z,y),x));
    visit[z][y][x]=true;
    dist[z][y][x]=0;

    while(!q.empty()){
        int curZ = q.front().first.first;
        int curY = q.front().first.second;
        int curX = q.front().second;

        q.pop();
        //cout<<"z:"<<curZ<<" y:"<<curY<<" x:"<<curX<<'\n';

        if(curZ==endPointZ && curY==endPointY && curX==endPointX){
            cout<<"Escaped in "<<dist[curZ][curY][curX]<<" minute(s)."<<'\n';
            return;
        }
        for(int i=0;i<6;i++){
            int nextZ = curZ + dz[i];
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            
            if(nextZ<0 || nextY<0 || nextX<0){
                continue;
            }
            if(nextZ>=l || nextY>=r || nextX>=c){
                continue;
            }
            if(visit[nextZ][nextY][nextX]==false && arr[nextZ][nextY][nextX]==1){
                visit[nextZ][nextY][nextX]=true;
                q.push(make_pair(make_pair(nextZ,nextY),nextX));
                dist[nextZ][nextY][nextX] = dist[curZ][curY][curX] + 1;
                //cout<<"nextZ:"<<nextZ<<" nextY:"<<nextY<<" nextX:"<<nextX<<'\n';
                //cout<<dist[nextZ][nextY][nextX]<<'\n';
            }
            
        }
    }
    cout<<"Trapped!"<<'\n';

    

}

void initVisit(){
    for(int i=0;i<l;i++){
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                visit[i][j][k]=false;
            }
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    while(1){
        cin>>l>>r>>c;
        if(l==0 && r==0 && c==0){
            break;
        }
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                string str;
                cin>>str;
                for(int k=0;k<c;k++){
                    
                    if(str[k]=='S'){
                        startingPointZ=i;
                        startingPointY=j;
                        startingPointX=k;
                        arr[i][j][k] = 1;
                    }else if(str[k]=='E'){
                        endPointZ = i;
                        endPointY = j;
                        endPointX = k;
                        arr[i][j][k] = 1;
                    }else if(str[k]=='.'){
                        //방문할 수 있는 곳
                        arr[i][j][k] = 1;
                    }else if(str[k]=='#'){
                        //막혀 있는 곳
                        arr[i][j][k]=0;
                    }
                }
            }
        }
        //cout<<endPointZ<<" "<<endPointY<<" "<<endPointX<<'\n';
        /**
         * 
         * 
         * */
        bfs(startingPointZ,startingPointY,startingPointX);
        initVisit();
        while(!q.empty()){
            q.pop();
        }




    }
    
    
    return 0;
}