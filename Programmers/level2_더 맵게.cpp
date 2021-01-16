#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<>> pq;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    int add = 0;
    while(pq.top()<K){
        if(pq.size()==1){
            answer = -1;
            break;
        }
        int a1 = pq.top();
        pq.pop();
        int a2 = pq.top();
        pq.pop();
        answer++;
        pq.push(a1+(a2*2));
    }
    
    
    return answer;
}