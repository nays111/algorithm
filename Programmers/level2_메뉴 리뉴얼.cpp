#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <unordered_map>


using namespace std;

unordered_map<string,int> mp;


//dfs를 사용하여 메뉴 조합 구하기
void dfs(int cnt,int size,string str,string target){
    if(cnt==size){
        //코스요리 메뉴는 최소 2가지 이상의 단품 메뉴로 구성됨
        if(target.size()>=2){
            mp[target]++;
        }
        return;
    }else{
        dfs(cnt+1,size,str,target+str[cnt]);
        dfs(cnt+1,size,str,target);
    }
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0;i<orders.size();i++){
        string str = orders[i];
        sort(str.begin(),str.end());
        dfs(0,str.size(),str,"");
    }
   
    
    for(int i=0;i<course.size();i++){
        
        int biggest = 0;
        //n개의 재료를 쓴 조합 중에 가장 많이 나온 횟수 구하기
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->first.size() == course[i]){
                biggest = max(biggest,it->second);
            }
        }
        
        for(auto it = mp.begin(); it!=mp.end();it++){
            if(it->first.size()==course[i] && (it->second)==biggest && it->second>=2){
                answer.push_back(it->first);
            }
        }
    }
    
    sort(answer.begin(),answer.end());
    
    return answer;
}