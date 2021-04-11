#include <string>
#include <vector>
#include <iostream>

#include <algorithm>
#include <map>

using namespace std;



int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    
    int col_size = relation[0].size();
    int row_size = relation.size();
    vector<int> unique_set;
    
    
    for(int i=1;i< (1<<col_size);i++){
        //i = 1~16
        
        map<string,int> mp;
        for(int j=0;j<row_size;j++){
            string str="";
            for(int k=0;k<col_size;k++){
                
                if(i & (1<<k)){
                    str+=relation[j][k];    
                }
            }
            mp[str]++;
        }
        

        
        //유일성을 만족하는지 검사
        bool flag = false;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second >= 2){
                flag  = true;
            }
        }
        //유일성을 만족하는 경우
        if(flag==false){
            unique_set.push_back(i);    
        }
    }
    
    sort(unique_set.begin(),unique_set.end());
    

    bool visit[1001] = {false,};
    
    for(int i=0;i<unique_set.size();i++){
        int n = unique_set[i];
        for(int j=i+1;j<unique_set.size();j++){
            int m = unique_set[j];
            int x = n&m;
            
            if(x==n && visit[j] ==false){
                visit[j] = true;
                
            }
        }
    }
    for(int i=0;i<unique_set.size();i++){
        if(visit[i]==false){
            answer++;
        }
    }
    
    
    return answer;
}