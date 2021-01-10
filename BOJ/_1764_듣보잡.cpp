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
    int n,m;
    cin>>n>>m;
    set<string> deutdo;
    set<string> deutbodo;
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        deutdo.insert(name);
    }
    for(int i=0;i<m;i++){
        string name;
        cin>>name;
        if(deutdo.find(name)!=deutdo.end()){
            deutbodo.insert(name);
        }
    }
    cout<<deutbodo.size()<<'\n';
    for(auto i=deutbodo.begin();i!=deutbodo.end();i++){
        cout<<*i<<'\n';
    }

    return 0;
}