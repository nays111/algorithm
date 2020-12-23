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
    int N;
    cin>>N;
    queue<int> q;
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    
    while(!q.empty()){        
        int temp = q.front();
        cout<<temp<<" ";
        q.pop();
        int temp2 = q.front();
        q.pop();
        q.push(temp2);        
    }
    
    return 0;
}