#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<pair<string,string>,string> p1, pair<pair<string,string>,string> p2){
    string head1 = p1.first.first;
    string head2 = p2.first.first;
    transform(head1.begin(),head1.end(),head1.begin(),::toupper);
    transform(head2.begin(),head2.end(),head2.begin(),::toupper);
    
    if(head1==head2){
        int number1 = stoi(p1.first.second);
        int number2 = stoi(p2.first.second);
        return number1 < number2;
    }else{
        return head1 < head2;
    }
    
    
}



vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<pair<pair<string,string>,string>> v;
    for(int i=0;i<files.size();i++){
        int index = 0;
        string file = files[i];
        
        string head = "";

        //HEAD 뽑아내기
        while(1){
            
            
            if(file[index]>='0' && file[index]<='9'){
                //숫자면 break;
                break;
            }
            head+=file[index];
            index++;
            
        }
        //cout<<"head:"<<head<<" ";
        
        string number="";
        while(1){
            if(file[index] <'0' || file[index]>'9'){
                //숫자가 아니면 break;
                break;
            }
            number+=file[index];
            index++;
        }
        //cout<<"number:"<<number<<" ";
        string tail="";
        while(1){
            if(index==file.size()){
                break;
            }
            tail+=file[index];
            index++;
        }
        //cout<<"index:"<<tail<<'\n';
        
        v.push_back({{head,number},tail});
    }
    
    // 안정 정렬로 정렬해야한다!!!!
    stable_sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        string temp = v[i].first.first + v[i].first.second+v[i].second;
        answer.push_back(temp);
    }
    
    return answer;
}