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
int n,m;
vector<int> v(9);
void backTracking(int start,int index){
    if(index==m){
        for(int i=0;i<m;i++){
            cout<<v[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    for(int i=start;i<n;i++){
        v[index]=i+1;
        backTracking(i+1,index+1);

    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    backTracking(0,0);    
    
    return 0;
}