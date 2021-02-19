#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    int cnt = 0;
    for(int i=0;i<operations.size();i++){
        
        if(cnt==0){
            while(!max_heap.empty()){
                max_heap.pop();
            }
            while(!min_heap.empty()){
                min_heap.pop();
            }
        }
        
        
        if(operations[i][0]=='I'){
            int num = stoi(operations[i].substr(2));
            max_heap.push(num);
            min_heap.push(num);
            cnt++;
        }else if(operations[i][0]=='D'){
            
            
            
            if(operations[i][2]=='1'){
                if(cnt!=0){
                    max_heap.pop();
                    cnt--;
                }
                
            }else{
                if(cnt!=0){
                    min_heap.pop();
                    cnt--;
                }
                
            }
        }
    }
    if(cnt==0){
        answer[0]=0;
        answer[1]=0;
    }else{
        answer[0] = max_heap.top();
        answer[1] = min_heap.top();
    }
    

    
    return answer;
}