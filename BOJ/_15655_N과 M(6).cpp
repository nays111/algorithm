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
vector<int> temp(9);
bool visit[9];
vector<int> v;
void func(int cnt,int index){
    if(cnt==m){
        for(int i=0;i<cnt;i++){
            cout<<temp[i]<<" ";
        }
        cout<<'\n';
        return;
    }else{
        for(int i=index;i<n;i++){
            if(visit[i]==false){                
                visit[i]=true;
                temp[cnt]=v[i];
                //cout<<"cnt:"<<cnt<<"index: "<<index<<'\n';
                func(cnt+1,i+1);
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