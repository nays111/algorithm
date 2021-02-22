#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=0;i<skill_trees.size();i++){
        string target = skill_trees[i];
        vector<int> memo;
        for(int j=0;j<target.size();j++){
            for(int k=0;k<skill.size();k++){
                if(target[j]==skill[k]){
                    memo.push_back(k);
                }
            }
        }
        bool flag = false;
        for(int j=0;j<memo.size();j++){
            if(memo[j]!=j){
                flag = true;
            }
        }
        if(flag==false){
            answer++;
        }
    }
     
    return answer;
}