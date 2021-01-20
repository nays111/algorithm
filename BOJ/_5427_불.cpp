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
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int w,h; //h-y, w-x
char arr[1001][1001];
bool visit[1001][1001];
int startPointY;
int startPointX;
vector<pair<int,int>> fire;

int bfs(){
    queue<pair<int,int>> q;
    queue<pair<int,int>> fires;
    q.push(make_pair(startPointY,startPointX));
    //cout<<startPointY<<" "<<startPointX<<'\n';
    for(int i=0;i<fire.size();i++){
        fires.push(make_pair(fire[i].first,fire[i].second));
    }
    int answer = 1;


    while(!q.empty()){
        // for(int i=0;i<h;i++){
        //     for(int j=0;j<w;j++){
        //         cout<<arr[i][j];
        //     }
        //     cout<<'\n';
        // }


        // for(int i=0;i<h;i++){
        //     for(int j=0;j<w;j++){
        //         cout<<visit[i][j];
        //     }
        //     cout<<'\n';
        // }


        int fireSize = fires.size();
        for(int i=0;i<fireSize;i++){
            int curY = fires.front().first;
            int curX = fires.front().second;
            fires.pop();
            for(int j=0;j<4;j++){
                int nextY = curY + dy[j];
                int nextX = curX + dx[j];
                if(nextY<0 || nextX<0 || nextY>=h || nextX>=w){
                    continue;
                }
                if(arr[nextY][nextX]=='.'){
                    arr[nextY][nextX]='*';
                    fires.push(make_pair(nextY,nextX));
                }
            }
        }
        int queueSize = q.size();
        for(int i=0;i<queueSize;i++){
            //사람 움직이는거
            int curY = q.front().first;
            int curX = q.front().second;
            q.pop();
            if(curY==0 || curX==0 || curY==h-1 || curX==w-1){
                    //벽쪽이면 탈출가능
                    return answer;
            }
            for(int j=0;j<4;j++){
                int nextY = curY+dy[j];
                int nextX = curX+dx[j];

                if(nextY<0 || nextX<0 || nextY>=h || nextX>=w){
                    continue;
                }
                
                if(visit[nextY][nextX]==false && arr[nextY][nextX]=='.' ){
                    //방문 안함 + 빈공간이어야지 이동가능
                    //방문체크
                    visit[nextY][nextX]=true;
                    //큐 삽입
                    q.push(make_pair(nextY,nextX));
                    
                }

            }
        }

        answer++;
    }
    return -1;

}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        fire.clear(); //큐 초기화
        memset(visit,false,sizeof(visit)); //방문 초기화
        
        cin>>w>>h;
        
        
        for(int j=0;j<h;j++){
            string str;
            cin>>str;
            for(int k=0;k<w;k++){
                arr[j][k]=str[k];
                if(str[k]=='@'){
                    startPointY=j;
                    startPointX=k;
                }else if(str[k]=='*'){
                    fire.push_back(make_pair(j,k));
                }
            }
        }
        
        int a = bfs();
        if(a==-1){
            cout<<"IMPOSSIBLE"<<'\n';
        }else{
            cout<<a<<'\n';
        }

    }
    
    return 0;
}