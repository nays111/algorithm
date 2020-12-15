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
    priority_queue<int,vector<int>,greater<int>> pq;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        if(a==0 && pq.empty()){
            cout<<0;
        }else if(a==0){
            cout<<pq.top();
            pq.pop();
        }else{
            pq.push(a);
        }
    }
    
    return 0;

}