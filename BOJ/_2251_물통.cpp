#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <string>
using namespace std;
bool visit[201][201][201];
int a,b,c;
vector<int> answer;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    
    cin>>a>>b>>c;

    


    queue <pair<pair<int,int>,int>> q;

    q.push(make_pair(make_pair(0,0),c));
    
    
    
    
    while(!q.empty()){
        int curA = q.front().first.first; //A에 있는 물의 양
        int curB = q.front().first.second; //B에 있는 물의 양
        int curC = q.front().second; //C에 있는 물의 양
        q.pop();
        if(visit[curA][curB][curC]==true){
            continue;
        }

        visit[curA][curB][curC] = true;
        if(curA==0){
            answer.push_back(curC);
        }

        
        //a물통에서 b물통으로 줄때
        if(curA+curB>b){
            q.push({{curA+curB-b,b},curC});
        }else{
            q.push({{0,curA+curB},curC});
        }
        //a물통에서 c물통으로 줄때
        if(curA+curC>c){
            q.push({{curA+curC-c,curB},c});
        }else{
            q.push({{0,curB},curA+curC});
        }
        //b물통에서 a물통으로 줄때
        if(curA+curB>a){
            q.push({{a,curA+curB-a},curC});
        }else{
            q.push({{curA+curB,0},curC});
        }
        //b물통에서 c물통으로 줄때
        if(curB+curC>c){
            q.push({{curA,curB+curC-c},c});
        }else{
            q.push({{curA,0},curB+curC});
        }
        //c물통에서 a물통으로 줄떄
        if(curA+curC>a){
            q.push({{a,curB},curA+curC-a});
        }else{
            q.push({{curA+curC,curB},0});
        }
        //c물통에서 b물통으로 줄떄
        if(curC+curB>b){
            q.push({{curA,b},curB+curC-b});
        }else{
            q.push({{curA,curB+curC},0});
        }
        


    }
    sort(answer.begin(),answer.end());
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }


    return 0;
}