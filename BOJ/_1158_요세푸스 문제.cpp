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
    int N,K;
    cin>>N>>K;
    queue<int> q;
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    cout<<"<";
    while(1){
        for(int i=0;i<K-1;i++){
            int a=q.front();
            q.pop();
            q.push(a);
        }
        cout<<q.front();
        q.pop();
        if(q.size()==0){
            break;
        }
        cout<<", ";
    }
    cout<<">";
    return 0;
}