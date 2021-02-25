#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    bool flag = false;
    
    for(int i=1;i<words.size();i++){
        int person = i%n + 1;
        int turnCount = i/n + 1;
        int size = words[i-1].size();
        char lastChar = words[i-1][size-1];
        char firstChar = words[i][0];
        
        for(int j=0;j<i;j++){
            if(words[i]==words[j]){
                answer.push_back(person);
                answer.push_back(turnCount);
                flag = true;
                break;
            }
        }
        if(firstChar!=lastChar){
            answer.push_back(person);
            answer.push_back(turnCount);
            flag = true;
            break;
        }  
        if(flag==true){
            return answer;
        }
    }
            
    if(answer.empty()){
        answer.push_back(0);
        answer.push_back(0);

    }

    return answer;
}