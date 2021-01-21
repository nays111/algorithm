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

bool visit[100000];
int n,t,g;
int bfs(int start,int target){
    queue<pair<int,int>> q; //first : number, second : distance
    q.push(make_pair(start,0));
    visit[start] = true;
    while(!q.empty()){
        int cur = q.front().first;
        int result = q.front().second;
        q.pop();
        if(result>t){
            return -1;
        }
        if(cur==target){
            return result;
        }
        //A버튼 관련
        int nextA = cur+1;
        if(nextA > 99999){
            continue;
        }
        if(nextA < 100000 && visit[nextA]==false){
            visit[nextA]=true;
            q.push(make_pair(nextA,result+1));
        }
        //B버튼 관련
        int nextB = cur*2;
        if(nextB>99999){//2곱한순간 넘어가면 일단 탈출 실패
            continue;
        }
        int temp = nextB;
        int a = 1;
        while(temp!=0){
            temp = temp/10;
            a = a*10;
        }
        nextB = nextB - (a/10);
        if(nextB < 100000 && visit[nextB]==false){
            visit[nextB]=true;
            q.push(make_pair(nextB,result+1));
        }

    }
    return -1;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>t>>g;
    // if(bfs(n,g)==-1){
    //     cout<<"ANG";
    // }else{
    //     cout<<bfs(n,g);
    // }
    // cout<<'\n';
    
    int ans = bfs(n,g);
    if(ans==-1){
        cout<<"ANG";
    }else{
        cout<<ans;
    }
    
    return 0;

}