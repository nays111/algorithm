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
    while(1){
        int n,m,k;
        cin>>n>>k>>m;
        
        if(n==0 && m==0 && k==0){
            break;
        }
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }

        m--;
        k--;
        while(1){

            v.erase(v.begin()+m);
            m=m+k;
            if(m>=v.size()){
                m=m%v.size();
            }
            if(v.size()==1){
                break;
            }

        }
        cout<<v[0]<<'\n';
        
    }
    
    return 0;
}