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
    int a,b;
    cin>>a>>b;
    string strA = to_string(a);
    string strB = to_string(b);
    string tempA;
    string tempB;
    for(int i=strA.size()-1;i>=0;i--){
        tempA.push_back(strA[i]);
    }
    for(int i=strB.size()-1;i>=0;i--){
        tempB.push_back(strB[i]);
    }
    //tempA랑 tempB를 숫자로 변환하여 대소 비교
    if(stoi(tempA)>stoi(tempB)){
        cout<<stoi(tempA);
    }else{
        cout<<stoi(tempB);
    }
    return 0;
}