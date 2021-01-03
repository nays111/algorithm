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
    //10+8+10+4+6+4
    //9,7,9,3,5,3
    //A,B,C -> 3
    //D,E,F -> 4
    int arr[26]={3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
    string str;
    cin>>str;
    //A : 65 ~ Z : 90
    int answer = 0;
    for(int i=0;i<str.size();i++){
        int a = str[i]; //A=65
        answer+=arr[a-65];
    }
    cout<<answer;
    
    return 0;
}