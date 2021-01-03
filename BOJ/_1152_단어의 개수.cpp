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
    getline(cin,str);
    int count = 1;
    for(int i=0;i<str.size();i++){
        if(str[i]==' '){
            count++;
        }
    }
    if(str[0]==' '){
        count--;
    }
    if(str[str.size()-1]==' '){
        count--;
    }
    cout<<count;
    return 0;
}