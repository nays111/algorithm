#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool visit[10001];

void dfs(vector<string> &answer,vector<string> &temp,vector<vector<string>> &tickets,string cur,int count){
    
    temp.push_back(cur);
    
    if(count==tickets.size() && answer.empty()){
        answer = temp;
        return;
    }
    
    for(int i=0;i<tickets.size();i++){
        if(tickets[i][0]==cur && visit[i]==false){
            visit[i]=true;
            dfs(answer,temp,tickets,tickets[i][1],count+1);
            visit[i]=false;
        }
    }
    temp.pop_back();
}



vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<string> temp;    
    sort(tickets.begin(),tickets.end());
    dfs(answer,temp,tickets,"ICN",0);

    return answer;
}