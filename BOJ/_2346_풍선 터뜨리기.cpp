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

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    deque<pair<int,int>> dq;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        dq.push_back(make_pair(i,a));
    }
    while(!dq.empty()){

        int frontNum = dq.front().second;
        cout<<dq.front().first<<" ";
        dq.pop_front();
        if(frontNum>0 && !dq.empty()){
            for(int i=0;i<frontNum-1;i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }else if (frontNum<0 && !dq.empty()){
            for(int i=0;i<abs(frontNum);i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        
    }
}