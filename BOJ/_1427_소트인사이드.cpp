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
bool desc(char a,char b){
    return a>b;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    string str = to_string(N);
    vector<char> answer;
    for(int i=0;i<str.length();i++){
        answer.push_back(str[i]);
    }
    sort(answer.begin(),answer.end(),desc);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i];
    }
    return 0;
}