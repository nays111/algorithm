#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";

    transform(s.begin(),s.end(),s.begin(),::tolower);
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==' '){
            s[i+1]=toupper(s[i+1]);
        }
    }
    s[0]=toupper(s[0]);
    answer=s;
    return answer;
}