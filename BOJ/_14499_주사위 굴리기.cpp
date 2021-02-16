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
int n,m,x,y,k;
int arr[21][21];
vector<int> command;

//0->동 1->서 2->남 3->북
int dy[]={0,0,-1,1};
int dx[]={1,-1,0,0};
int dice[7]={0,};


void roll(int d){
    int temp[7]={0,};
    for(int i=1;i<=6;i++){
        temp[i]=dice[i];
    }
    if(d==0){ //동쪽
        dice[1] = temp[4];
        dice[3] = temp[1];
        dice[4] = temp[6];
        dice[6] = temp[3];
    }else if(d==1){ //서쪽
        dice[1] = temp[3];
        dice[3] = temp[6];
        dice[4] = temp[1];
        dice[6] = temp[4];
    }else if(d==2){ //북쪽
        dice[1] = temp[5];
        dice[2] = temp[1];
        dice[5] = temp[6];
        dice[6] = temp[2];
    }else if(d==3){ //남쪽
        dice[1] = temp[2];
        dice[2] = temp[6];
        dice[5] = temp[1];
        dice[6] = temp[5];
    }


}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m>>y>>x>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<k;i++){
        int d;
        cin>>d;
        d--;

        int nextY = dy[d] + y;
        int nextX = dx[d] + x;

        if(nextY >=0 && nextX>=0 && nextY<n && nextX<m){
            
            roll(d);
            if(arr[nextY][nextX]==0){
                arr[nextY][nextX]=dice[6];
            }else{
                dice[6] = arr[nextY][nextX];
                arr[nextY][nextX]=0;
            }
            y=nextY;
            x=nextX;
            cout<<dice[1]<<'\n';
        }
    }  
    

    return 0;
}