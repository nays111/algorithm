#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//연산자 계산
long long calculate(long long value1,long long value2,char operators){
    long long result;
    if(operators=='+'){
        result =  value1 + value2;
    }else if(operators == '-'){
        result =  value1 - value2;
    }else if(operators == '*'){
        result = value1 * value2;
    }
    return result;
}


long long solution(string expression) {
    long long answer = 0;
    
    
    //숫자와 연산자를 각각 분리
    vector<long long> numbers;
    vector<char> operators;
    
    string temp;
    for(int i=0;i<expression.size();i++){
        if(expression[i]=='-' || expression[i]=='+' || expression[i]=='*'){
            operators.push_back(expression[i]);
            long long num = stoi(temp);
            numbers.push_back(num);
            temp="";
        }
        if(expression[i]>='0' && expression[i] <= '9'){
            temp+=expression[i];
        }
    }
    numbers.push_back(stoi(temp));
    

    
    
    //연산자의 우선순위를 순열을 통해
    vector<char> priority_operators={'*','+','-'};
    sort(priority_operators.begin(),priority_operators.end());
    
    
    //next_permutation으로 검사
    do{
        //복사본 생성
        vector<long long> copy_numbers = numbers;
        vector<char> copy_operators = operators;
        
        
        
        for(int i=0;i<priority_operators.size();i++){
            
            
            for(int j=0;j<copy_operators.size();j++){
                if(priority_operators[i] == copy_operators[j]){
                    long long value = calculate(copy_numbers[j],copy_numbers[j+1],copy_operators[j]);
                    //기존 값을 지우고 계산에서 얻은 값을 삽입
                    copy_numbers[j] = value;
                    copy_numbers.erase(copy_numbers.begin()+j+1);
                    
                    //기존 연산자도 사용했으므로 지워준다.
                    copy_operators.erase(copy_operators.begin()+j);
                    
                    //다시 반복문을 돌아야하므로 인덱스 수정
                    j--;
                    
                }
            }
        }
        //계산결과
        //cout<<copy_numbers[0];
        answer = max(answer,abs(copy_numbers[0]));
    }while(next_permutation(priority_operators.begin(),priority_operators.end()));
    
    
    
    return answer;
}