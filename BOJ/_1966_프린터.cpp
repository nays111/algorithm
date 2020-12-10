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
    int num;
    
    cin>>num;
    for(int i=0;i<num;i++){
        int N,M;
        int count=0;
        queue <pair<int,int>> q;
        priority_queue <int> pq;
        cin>>N>>M;
        for(int i=0;i<N;i++){
            int value;
            cin>>value;
            q.push({i,value});//pair는 이렇게 삽입 (i는 큐의 인덱스를 나타냄)
            pq.push(value);
        }
        while(!q.empty()){
            int index = q.front().first; //인덱스를 뜻함
            int val = q.front().second;// 실제값을 뜻함
            q.pop();
            if(pq.top()==val){ //pq의 우선순위는 내림차순 (4,3,2,1) -> 즉 중요도가 제일 높은게 top에 있음
                //만약 같다면, 가장 가장 우선순위가 높다는 것이므로 프린터에서 출력
                pq.pop(); //우선순위 가장 큰거 찾아냈으니깐 필요없으니깐 pop
                count++;//출력횟수 증가
                if(index==M){// 만약 내가 궁금한 문서의 위치라면
                    cout<<count;
                    break;
                }
            }else{
                q.push({index,val});//중요도가 가장 높은게 아니니깐 다시 맨 뒤로 보내서 나중에 다시 비교
            }
        }

    }
    return 0;
}