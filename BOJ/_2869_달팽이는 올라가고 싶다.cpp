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
    long long V,A,B;
    cin>>A>>B>>V;
    long long day=0;

    
    if((V-A)%(A-B)==0){
        cout<<(V-A)/(A-B)+2;
    }else{
        cout<<(V-A)/(A-B)+1;
    }
    
    
    return 0;

}