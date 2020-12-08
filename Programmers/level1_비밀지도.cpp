#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    for(int i=0;i<n;i++){
        int temp = arr1[i]|arr2[i];
        answer[i].assign(" ",n);
        for(int j=n-1;j>=0;j--){
            if(temp%2==0){
                answer[i][j]=' ';
            }else{
                answer[i][j]='#';
            }
            temp=temp/2;
        }
    }
    
    return answer;
}