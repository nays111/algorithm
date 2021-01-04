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
    int x,y,w,h;
    cin>>x>>y>>w>>h;
    int mini = min(w-x,min(x,min(y,h-y)));
    cout<<mini;
    return 0;
}