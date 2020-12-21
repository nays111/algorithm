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
    int n = str.size();
    if(n%3 ==1){
        cout<<str[0];
    }else if(n%3==2){
        cout<<(str[0]-'0')*2 + (str[1]-'0');
    }
    for(int i=n%3;i<n;i+=3){
        cout<<(str[i]-'0')*4+(str[i+1]-'0')*2+(str[i+2]-'0');
    }
    return 0;
}