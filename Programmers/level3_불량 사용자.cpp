#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;


set<string> s;
bool visit[8];

void dfs(vector<string> &user_id,vector<string> &banned_id, int cnt,string str){
    if(cnt == banned_id.size()){
        //cout<<str<<" ";
        sort(str.begin(),str.end());
        //cout<<str<<'\n';
        s.insert(str);
        return;
    }else{
        string ban = banned_id[cnt];
        
        for(int i=0;i<user_id.size();i++){
            string target = user_id[i];
            
            if(visit[i] == true){
                continue;
            }
            if(ban.size()!=target.size()){
                continue;
            }
            bool flag = false;
            if(ban.size()==target.size() ){
                for(int j=0;j<ban.size();j++){
                    if(ban[j]=='*'){
                        continue;
                    }
                    if(ban[j]!=target[j]){
                        flag = true;
                        break;
                    }
                }
            }
            
            if(flag == false){
                
                visit[i] = true;
                dfs(user_id,banned_id,cnt+1,str+to_string(i));
                visit[i] = false;
            }
        } 
    }
    
    
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    dfs(user_id,banned_id,0,"");
    answer = s.size();
    return answer;
}