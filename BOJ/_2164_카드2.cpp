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
    int N;
    cin>>N;
    int answer;
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    while(!q.empty()){
        q.pop();
        if(q.size()==1){
            answer=q.front();
            break;
        }
        int n=q.front();
        q.pop();
        q.push(n);
    }
    cout<<answer;
    return 0;
}