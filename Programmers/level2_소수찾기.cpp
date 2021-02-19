#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

bool isPrime(int n){
    if(n==0 || n==1){
        return false;
    }else{
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    
}

int solution(string numbers) {
    int answer = 0;
    vector<char> v;
    vector<int> v2;
    for(int i=0;i<numbers.size();i++){
        v.push_back(numbers[i]);
    }
    sort(v.begin(),v.end());
    do{
        string str;
        for(int i=0;i<v.size();i++){
            str=str+v[i];
            v2.push_back(stoi(str));
        }     
    }while(next_permutation(v.begin(),v.end()));
    sort(v2.begin(),v2.end());
    v2.erase(unique(v2.begin(),v2.end()),v2.end());
    for(int i=0;i<v2.size();i++){
        if(isPrime(v2[i])==true){
            answer++;
        }
    }
    return answer;
}