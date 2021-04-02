#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    //1단계 : new_id 소문자로 치환
    transform(new_id.begin(),new_id.end(),new_id.begin(),::tolower);
    
    cout<<"1단계 이후:"<<new_id<<" "<<new_id.size()<<'\n';
    //2단계 : new_id : 특수문자 제거
    string new_id_2;
    for(int i=0;i<new_id.size();i++){
        if((new_id[i]>='a' && new_id[i]<='z') || (new_id[i]>='0' && new_id[i] <='9') || new_id[i]=='-' ||
           new_id[i]=='_' || new_id[i]=='.'){
            new_id_2 = new_id_2 + new_id[i];
        }
    }
    cout<<"2단계 이후:"<<new_id_2<<" "<<new_id_2.size()<<'\n';
    //3단계 : .가 연속으로 두 번이상 나올 경우 제거
    string new_id_3;
    int index=0;
    for(;index<new_id_2.size();index++){
        if(new_id_2[index]=='.'){
            new_id_3 = new_id_3 + new_id_2[index];
            while(new_id_2[index]=='.'){
                index++;
            }
            index--;
        }else{
            new_id_3 = new_id_3 + new_id_2[index];
        }
        
    }
    cout<<"3단계 이후:"<<new_id_3<<" "<<new_id_3.size()<<'\n';
    
    //4 단계 : . 이 처음이나 맨끝에 위치한다면 제거
    string new_id_4="";
    for(int i=0;i<new_id_3.size();i++){
        if(i==0 && new_id_3[i]=='.'){
            continue;
        }
        if(i==new_id_3.size()-1 && new_id_3[i]=='.'){
            continue;
        }
        new_id_4 = new_id_4 + new_id_3[i];
    }
    cout<<"4단계 이후:"<<new_id_4<<" "<<new_id_4.size()<<'\n';

    ////////////////////////////////////////////////////
    //5 단계 : new_id 가 빈 문자열이면 new_id에 "a"를 대입//
    ///////////////////////////////////////////////////
    string new_id_5="";
    if(new_id_4==""){
        new_id_5 +='a';
    }else{
        new_id_5 = new_id_4;
    }
    cout<<"5단계 이후:"<<new_id_5<<'\n';
    
    ////////////////////////////////////////////////////
    //6단계 : 16자 이상이면, 
    ////////////////////////////////////////////////////
    string new_id_6;
    if(new_id_5.size()>=16){
        for(int i=0;i<15;i++){
            new_id_6 = new_id_6 + new_id_5[i];
        }
    }else{
        new_id_6=new_id_5;
    }
    //cout<<"5단계 이후:"<<new_id_6<<'\n';
    if(new_id_6[14]=='.'){
        new_id_6.erase(new_id_6.begin()+14);
    }
    cout<<"6단계 이후:"<<new_id_6<<'\n';
    
    if(new_id_6.size()<=2){
        while(new_id_6.size()!=3){
            new_id_6 = new_id_6+new_id_6[new_id_6.size()-1];
        }
    }
    cout<<"7단계 이후:"<<new_id_6<<'\n';
    
    answer = new_id_6;
    return answer;
}