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
    int answer = 0;
    int temp = 0;
    priority_queue<int,vector<int>,greater<>> pq;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        pq.push(a);
    }
    while(pq.size()>1){
        int t1 = pq.top();
        pq.pop();
        int t2 = pq.top();
        pq.pop();
        int sum = t1+t2;
        pq.push(sum);
        answer = answer + sum;
    }
    cout<<answer;


}