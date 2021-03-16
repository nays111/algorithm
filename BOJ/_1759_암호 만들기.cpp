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
    vector<int> np(m);
    for(int i=0;i<v.size()-n;i++){
        np[m-i-1]=1;
    }
    do{
        string temp="";
        bool flag = false;
        int cnt = 0;
        for(int i=0;i<m;i++){
            if(np[i]==0){
                if(v[i]=='a' || v[i]=='i' || v[i]=='e' || v[i]=='o' || v[i]=='u'){
                    flag = true;
                }else{
                    cnt++;
                }
                temp = temp+v[i];
            }
        }
        if(flag==true && cnt>=2){
            cout<<temp<<'\n';
        }
    }while(next_permutation(np.begin(),np.end()));
    
    return 0;
}