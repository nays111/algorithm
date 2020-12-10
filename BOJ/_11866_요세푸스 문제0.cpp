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
    queue<int> q;
    int N,K;
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    cout<<"<";
    while(!q.empty()){
        for(int i=0;i<K-1;i++){//K-1개만큼 빼줘야하므로
            q.push(q.front());
            q.pop();
        }
        if(q.size()==1){
            cout<<q.front()<<">";
        }else{
            cout<<q.front()<<", ";
        }
        q.pop();

    }
    return 0;
}