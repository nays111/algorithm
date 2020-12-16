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
    string str;
    cin>>str;
    int number = 0;
    int allS = 0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='L'){
            number++;
        }else{
            allS++;
        }
    }
    if(allS==str.size()){
        cout<<N;
    }else{
        cout<<((N+1)-(number/2));
    }

    return 0;
}