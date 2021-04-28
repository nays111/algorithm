#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    stack<int> st;
    int answerSize = number.size() - k;
    
    for(int i=0;i<number.size();i++){
        
        if(st.empty()){
            st.push(number[i]-'0');
        }else{
            while(!st.empty()){
                if(st.top() < number[i]-'0' && k > 0){
                    st.pop();
                    k--;
                }else{
                    break;
                }
                
                
            }
            st.push(number[i]-'0');        
        }
    }

    stack<int> temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    
    if(temp.size()==answerSize){
        while(!temp.empty()){
            answer += to_string(temp.top());
            temp.pop();
        }
    }else{
        for(int i=0;i<answerSize;i++){
            answer += to_string(temp.top());
            temp.pop();
        }
        
    }
    

    
    return answer;
}