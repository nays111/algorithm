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
    string str;
    cin>>str;
    int sum = 0;
    for(int i=0;i<str.size();i++){
        sum+=(str[i]-'0');
    }
    cout<<sum;

    return 0;
}