#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    set<string> v;
    
    for(int i=0;i<n;i++){
        int a = 0;
        string name;
        string status;
        cin>>name>>status;
        if(status=="enter"){
            v.insert(name);
            
        }else{
            v.erase(name);
        }
    }
    for(auto i=v.rbegin();i!=v.rend();i++){
        cout<<*i<<'\n';
    }

    

    return 0;
}