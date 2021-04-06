#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(int i=0;i<works.size();i++){
        pq.push(works[i]);
    }
    while(n>0){
        int temp = pq.top();
        pq.pop();
        temp--;
        if(temp < 0){
            return 0;
        }
        pq.push(temp);
        n--;
    }
    while(!pq.empty()){
        answer += (long long)pq.top() * (long long)pq.top();
        pq.pop();
    }
    
    return answer;
}