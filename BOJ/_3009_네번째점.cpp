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
    int x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    if(x1==x2){
        cout<<x3<<" ";
    }else if(x2==x3){
        cout<<x1<<" ";
    }else if(x1==x3){
        cout<<x2<<" ";
    }
    if(y1==y2){
        cout<<y3;
    }else if(y2==y3){
        cout<<y1;
    }else if(y1==y3){
        cout<<y2;
    }
    return 0;
}