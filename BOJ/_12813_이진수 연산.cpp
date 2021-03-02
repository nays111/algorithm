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

const int sizess=100000;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string str1,str2;
    cin>>str1>>str2;
    int arr1[sizess];
    int arr2[sizess];
    for(int i=0;i<sizess;i++){
        arr1[i]=str1[i]-'0';
    }
    for(int i=0;i<sizess;i++){
        arr2[i]=str2[i]-'0';
    }
    for(int i=0;i<sizess;i++){
        cout<<(arr1[i] && arr2[i]);
    }
    cout<<'\n';
    for(int i=0;i<sizess;i++){
        cout<<(arr1[i] || arr2[i]);
    }
    cout<<'\n';
    for(int i=0;i<sizess;i++){
        cout<<(arr1[i] != arr2[i]);
    }
    cout<<'\n';
    for(int i=0;i<sizess;i++){
        cout<<(!arr1[i]);
    }
    cout<<'\n';
    for(int i=0;i<sizess;i++){
        cout<<(!arr2[i]);
    }




    return 0;

}


