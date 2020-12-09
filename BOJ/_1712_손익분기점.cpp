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
    long long A,B,C;
    cin>>A>>B>>C;
    int n=1;
    if(B>=C){
        cout<<-1;
        return 0;
    }else{
        cout<<A/(C-B)+1;
    }

    return 0;

}