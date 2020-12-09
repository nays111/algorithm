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
    int count = 0;
    cin>>N;
    if(N==4 || N==7){
        cout<<-1;
        return 0;
    }
    count = N/5;
    switch(N%5){
        case 0:
            cout<<count;
            break;
        case 1:
            cout<<count+1;
            break;
        case 2:
            cout<<count+2;
            break;
        case 3:
            cout<<count+1;
            break;
        case 4:
            cout<<count+2;
            break;
    }
    return 0;

}