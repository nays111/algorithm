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


bool compare(string str1,string str2){
    if(str1.size() < str2.size()){
        return true;
    }else if(str1.size()==str2.size()){
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0;i<str1.size();i++){
            if(str1[i]>='0' && str1[i]<='9'){
                sum1 += str1[i]-'0';
            }
            if(str2[i]>='0' && str2[i]<='9'){
                sum2 += str2[i]-'0';
            }
        }
        if(sum1<sum2){
            return true;
        }
    }else{
        if(str1 < str2){
            return true;
        }
    }
    return false;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        v.push_back(str);
    }    
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<'\n';
    }


    return 0;
}