#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
bool visit[51];
bool change(string a,string b){
    int count = 0;
    for(int i=0;i<a.size();i++){
        if(a[i]==b[i]){
            count++;
        }
    }
    if(count==a.size()-1){
        return true;
    }else{
        return false;
    }
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    queue<pair<string,int>> q;
    q.push(make_pair(begin,0));

    while(!q.empty()){
        string cur = q.front().first;
        int len = q.front().second;
        if(cur==target){
            answer=len;
            break;
        }
        q.pop();
        for(int i=0;i<words.size();i++){
            if(change(cur,words[i])==true && visit[i]==false){
                q.push(make_pair(words[i],len+1));
                visit[i]=true;
            }
        }
    }
    return answer;
}