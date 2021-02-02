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
    string str;
    cin>>str;
    string answer;
    for(int i=0;i<str.size();i++){
        if(str[i]>='A' && str[i]<='Z'){
            answer +=str[i];
        }
    }
    cout<<answer;
    
    
    
    return 0;
}