#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int index = 0;
    string temp;
    for(int i=0;i<name.size();i++){
        temp+='A';
    }
    while(1){
        char ch = name[index];
        answer += min('A'-ch+26,ch-'A');
        name[index]='A';
        if(name==temp){
            break;
        }
        int right_count = 0;
        int left_count=0;
        int right_index = index;
        int left_index = index;
        while(name[right_index]=='A'){
            right_index++;
            if(right_index > name.size()-1){
                right_index = 0;
            }
            right_count++;
        }
        while(name[left_index]=='A'){
            left_index--;
            if(left_index<0){
                left_index = name.size()-1;
            }
            left_count++;
        }
        answer  = answer + min(right_count,left_count);
        if(right_count<=left_count){
            index = right_index;
        }else{
            index = left_index;
        }



    }
    return answer;
}