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
    string str;
    cin>>str;
    int arr[26];
    for(int i=0;i<26;i++){
        arr[i]=-1;
    }
    for(int i=0;i<str.size();i++){
        int st = str[i]; //97은 0번으로 가야함
        if(arr[st-97]!=-1){
            continue;
        }
        arr[st-97] = i;

    }
    /**
     * a (97)는 1번째, b는 2번째, c는 3번째, ..~~z(122)는 
     * */
    for(int i=0;i<26;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}