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
vector<int> v;
vector<int> temp(9);
bool visit[9];
void func(int cnt,int index){
    if(cnt==m){
        for(int i=0;i<cnt;i++){
            cout<<temp[i]<<" ";
        }
        cout<<'\n';
        return;
    }else{
        for(int i=0;i<v.size();i++){
            if(visit[i]==false){
                visit[i]=true;
                temp[index] = v[i];
                func(cnt+1,index+1);
                visit[i]=false;
            }
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    func(0,0);
    
    
    return 0;
}