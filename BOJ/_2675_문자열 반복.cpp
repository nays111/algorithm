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
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        string str;
        cin>>str;
        for(int j=0;j<str.size();j++){
            for(int k=0;k<a;k++){
                cout<<str[j];
            }
        }
        cout<<'\n';
    }
    return 0;
}