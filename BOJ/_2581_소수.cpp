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
    int min,max;
    cin>>min>>max;
    vector<int> v;
    for(int i=min;i<=max;i++){
        bool isPrime = true;
        
        for(int j=2;j<i;j++){
            if(i%j==0){
                isPrime = false;
            }
        }
        if(isPrime == true){
            if(i!=1){
                v.push_back(i);
            }   
        }
    }
    if(v.empty()){
        cout<<-1;
    }else{
        int sum = 0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            sum+=v[i];
        }
        cout<<sum<<'\n';
        cout<<v[0];
        
    }
    
    return 0;
}