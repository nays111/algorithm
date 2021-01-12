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
    priority_queue<int,vector<int>,greater<>> pq;
    for(int i=0;i<n*n;i++){
        int num;
        cin>>num;
        if(pq.size()<n){
            pq.push(num);
        }else if(pq.top()<num){
            pq.pop();
            pq.push(num);
        }
    }
    
    cout<<pq.top();
    // stack<int> st[n];
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         int n;
    //         cin>>n;
    //         st[j].push(n);
    //     }
    // }
    // for(int i=0;i<n-1;i++){

    //     int max = 0;
    //     int index = 0;
    //     for(int j=0;j<n;j++){
    //         if(max<st[j].top()){
    //             max = st[j].top();
    //             index = j;
    //         }
    //     }
        
    //     st[index].pop();
    // }
    // int answer = st[0].top();
    // for(int i=0;i<n;i++){
    //     if(st[i].top()>answer){
    //         answer=st[i].top();
    //     }
    // }
    // cout<<answer;
    
    return 0;
}