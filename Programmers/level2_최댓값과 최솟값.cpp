#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    
    for(int i=0;i<s.size();i++){
        //첫먼째 처리
        if(i==0 && s[i]=='-'){
            string temp="";
            for(int j=i;j<s.size();j++){
                if(s[j]==' '){
                    break;
                }
                temp+=s[j];
            }
            v.push_back(stoi(temp));
            continue;
        }
        if(i==0){
            string temp="";
            for(int j=i;j<s.size();j++){
                if(s[j]==' '){
                    break;
                }
                temp+=s[j];
            }
            v.push_back(stoi(temp));
        }
        
        
        
        if(s[i]==' '){
            string temp="";
            for(int j=i+1;j<s.size();j++){
                if(s[j]==' '){
                    break;
                }else{
                    temp=temp+s[j];    
                }
            }
            v.push_back(stoi(temp));
        }
    }
    
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    sort(v.begin(),v.end());
    answer = to_string(v[0])+" "+to_string(v[v.size()-1]);
    
    
    
    return answer;
}