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
    int A,B,C;
    cin>>A>>B>>C;
    int result = A*B*C;
    string str = to_string(result);
    int counts[10]={0};
    for(int i=0;i<str.size();i++){
        counts[str[i]-'0']++;
    }
    for(int i=0;i<10;i++){
        cout<<counts[i]<<endl;
    }
    return 0;
}