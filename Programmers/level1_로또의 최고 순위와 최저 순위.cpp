#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int unknownNumberCnt = 0;
vector<int> temp;
set<int> s;
int highest = 6;
int lowest = 1;
bool visit[46]={false,};



int getRank(vector <int> &lottos){
    int cnt = 0;
    
    for(int i=0;i<lottos.size();i++){
        
        if(s.find(lottos[i])!=s.end()){
            cnt++;
        }
        
    }
    
    if(cnt==6){
        return 1;
    }else if(cnt==5){
        return 2;
    }else if(cnt==4){
        return 3;   
    }else if(cnt==3){
        return 4;
    }else if(cnt==2){
        return 5;
    }else{
        return 6;
    }
}

void dfs(vector<int> &lottos,int index,int numIndex,int cnt){
    
    if(cnt == unknownNumberCnt){
        
        int rank = getRank(lottos);
        
        highest = min(highest,rank); //최고 순위
        lowest = max(lowest,rank); //최저 순위
    
        return;
    }
    
    for(int i=index;i<lottos.size();i++){
        if(lottos[i]==0){
            for(int j=numIndex;j<=45;j++){
                if(visit[j]==false){
                    visit[j] = true;
                    lottos[i] = j;
                    dfs(lottos,i+1,j+1,cnt+1);
                    visit[j] = false;
                    lottos[i] = 0;
                }
            }
        }
    }
}


vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    

    for(int i=0;i<win_nums.size();i++){
        s.insert(win_nums[i]);
    }
    
    
    for(int i=0;i<lottos.size();i++){
        if(lottos[i]==0){
            unknownNumberCnt++;
        }else{
            visit[i] = true;
        }
        
    }
    
    dfs(lottos,0,1,0);
    //cout<<highest<<" "<<lowest;
    answer.push_back(highest);
    answer.push_back(lowest);
    
    
    return answer;
}