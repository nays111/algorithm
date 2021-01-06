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
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        int dist = b-a;
        //거리가 x제곱이 되면 
        int x = sqrt(dist);
        //cout<<x;
        if(dist == x*x){ //16 = 4*4
            cout<<2*x - 1<<'\n';
        }else if(x*x+x<dist){ //4*4 + 4 <dist 
            cout<<2*x + 1<<'\n';
        }else{
            cout<<2*x<<'\n';
        }
    }
    
    return 0;

}