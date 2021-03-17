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
vector<char> v;
vector<char> temp(16);
bool visit[16];
void func(int cnt,int index){
    if(cnt==n){
        string str="";
        bool flag = false;
        int num=0;
        for(int i=0;i<cnt;i++){
            if(temp[i]=='a' || temp[i]=='e' || temp[i]=='i' || temp[i]=='o' || temp[i]=='u'){
                flag = true;
            }else{
                num++;
            }
            str = str + temp[i];
        }
        if(flag==true && num>=2){
            cout<<str<<'\n';
        }
        return;
    }else{
        for(int i=index;i<m;i++){
            if(visit[i]==false){
                visit[i]=true;
                temp[cnt]=v[i];
                func(cnt+1,i);
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
    for(int i=0;i<m;i++){
        char a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    func(0,0);

    return 0;
}