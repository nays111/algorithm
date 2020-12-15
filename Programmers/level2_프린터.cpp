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

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue <int> pq; //중요도만 담음
    queue <pair<int,int>> q; //중요도와 인덱스
    for(int i=0;i<priorities.size();i++){
        q.push(make_pair(i,priorities[i]));
        pq.push(priorities[i]);
    }
    int count = 0;
    while(!q.empty()){
        int index = q.front().first;
        int val = q.front().second;
        q.pop();
        if(pq.top()==val){//우선순위가 가장 높은 것을 찾으면
            pq.pop();
            count++;
            if(location==index){
                answer = count;
                break;
            }
        }else{
            q.push(make_pair(index,val));
        }
    }
    
    return answer;
}