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
    while(1){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0 && b==0 && c==0){
            break;
        }
        
        if((a*a + b*b == c*c)||(a*a+c*c==b*b)||(b*b+c*c==a*a)){
            cout<<"right"<<'\n';
        }else{
            cout<<"wrong"<<'\n';
        }
    }
    return 0;
}