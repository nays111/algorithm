#include <string>
#include <vector>
#include <stack>
#include <iostream>


using namespace std;

//올바른 괄호 문자열인지 판단
bool checkRight(string p){
    stack<char> st;
    for(int i=0;i<p.size();i++){
        if(p[i]=='('){
            st.push(p[i]);
        }else if(p[i]==')'){
            if(st.empty()){
                return false;
            }else if(!st.empty()){
                st.pop();
            }
        }
    }
    if(st.empty()){
        return true;
    }else{
        return false;
    }
}

string divide(string p){
    string u="";
    string v="";
    
    //1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
    if(p==""){
        return "";
    }
    
    
    int openCount = 0;
    int closeCount = 0;
    int index = 0;
    for(char c : p){
        if(c=='('){
            openCount++;
        }else{
            closeCount++;
        }
        index++;
        if(openCount == closeCount){
            break;
        }
        
    }
    u+=p.substr(0,index);
    v+=p.substr(index);
    
    
    string result="";
    //3. 문자열 u가 "올바른 관호 문자열"이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
    if(checkRight(u)==true){
        result+=u;
        result+=divide(v);
    }
    //4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
    else{
        // 4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
        result+="(";
        // 4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
        result+=divide(v);
        // 4-3. ')'를 다시 붙입니다. 
        result+=")";
        // 4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
        u = u.substr(1,u.size()-2);
        int size = u.size();
        for(int i=0;i<size;i++){
            if(u[i]=='('){
                result+=')';
            }else{
                result+='(';
            }
        }
    }
    return result;
}


string solution(string p) {
    string answer = "";
    
    //1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
    if(p.size()==0){
        return answer;
    }
    //올바른 괄호 문자열인지 체크
    //이미 올바른 괄호 문자열인 경우 그대로 return
    if(checkRight(p)==true){
        return p;
    }
    
    //균형잡힌 괄호 문자열인 경우
    answer = divide(p);
    
    
    
    return answer;
}