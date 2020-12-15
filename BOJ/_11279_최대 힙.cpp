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
    priority_queue<int> pq;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        if(num==0 && pq.empty()){
            cout<<0<<"\n";
        }else if(num==0){
            cout<<pq.top()<<"\n";
            pq.pop();
        }else{
            pq.push(num);
        }

    }
    return 0;

}