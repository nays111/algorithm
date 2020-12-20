#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
#include <functional>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    stack<int> s;
    vector<int> input(N);
    vector<int> answer(N);
    for(int i=0;i<N;i++){
        cin>>input[i];
    }
    s.push(0);
    for(int i=1;i<N;i++){
        if(s.empty()){
            s.push(i);//인덱스를 삽입
        }
        while(!s.empty() && input[s.top()] < input[i]){
            answer [s.top()] = input[i];
            s.pop();
        }
        s.push(i);//인덱스를 삽입
    }
    while(!s.empty()){
        answer[s.top()]=-1;
        s.pop();
    }
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<' ';
    }
    return 0;
}