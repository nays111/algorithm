#include <iostream>
#include <string>

using namespace std;

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);  
    string str;
    cin>>str;
    string temp="";
    bool minus = false;
    int answer = 0;
    for(int i=0;i<str.size();i++){
        //만약 기호일 경우
        if(str[i]=='-' || str[i]=='+' || str[i]=='\0'){
            if(minus){
                answer-=stoi(temp);
            }else{
                answer+=stoi(temp);
            }
            temp="";
            if(str[i] == '-'){
                minus = true;
            }
        }else{
            //기호가 아닐경우
            temp +=str[i];
        }  
    }
    cout<<answer;
    return 0;
}