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
    int count=0;
    int i=665;
    string str;
    while(i++){
        str = to_string(i);
        if(str.find("666")!= -1){
            count++;
        }
        if(count==N){
            cout<<i;
            break;
        }

    }
    return 0;

}