#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> m;
    for(int i=0;i<participant.size();i++){
        if(m.find(participant[i])==m.end()){//못찾았으면
            m[participant[i]]=1;
        }else{//찾았으면
            m[participant[i]]++;
        }
    }
    for(int i=0;i<completion.size();i++){
        if(m.find(completion[i])==m.end()){
            continue;
        }else{
            m[completion[i]]--;
        }
        
    }
    
    for(int i=0;i<participant.size();i++){
        if(m[participant[i]]!=0){
            answer=participant[i];
            break;
        }
    }
    
    return answer;
}