#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> mp;
    for(int i=0;i<record.size();i++){
        if(record[i][0]=='E'){
            string id;
            int j;
            for(j=6;record[i][j]!=' ';j++){
                id+=record[i][j];
            }
            string nickname;
            for(int k=j+1;k<record[i].size();k++){
                nickname+=record[i][k];
            }
            mp[id]=nickname;
        }else if(record[i][0]=='C'){
            string id;
            int j;
            for(j=7;record[i][j]!=' ';j++){
                id+=record[i][j];
            }
            string nickname;
            for(int k=j+1;k<record[i].size();k++){
                nickname+=record[i][k];
            }
            mp[id]=nickname;
        }
    }

    for(int i=0;i<record.size();i++){
        if(record[i][0]=='E'){
            string id;
            int j;
            for(j=6;record[i][j]!=' ';j++){    
                id+=record[i][j];
            }
            string nickname = mp[id];
            string answers = nickname+"님이 들어왔습니다.";
            answer.push_back(answers);
        }else if(record[i][0]=='L'){
            string id;
            int j;
            for(j=6;j<record[i].size();j++){    
                id+=record[i][j];
            }
            string nickname = mp[id];
            string answers = nickname+"님이 나갔습니다.";
            answer.push_back(answers);
        }
    }
    return answer;
}