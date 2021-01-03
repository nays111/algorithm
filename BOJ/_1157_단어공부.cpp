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
    int arr[26]={0};
    for(int i=0;i<str.size();i++){
        int ch = str[i];
        if(ch>90){
            //소문자인 경우
            arr[ch-97]++;
        }else{
            arr[ch-65]++;
        }
    }
    int max = 0;
    int count = 0;
    for(int i=0;i<26;i++){
        if(max<arr[i]){
            max = arr[i];
            count = i;
        }
    }
    // cout<<count;
    // cout<<arr[count];
    char ch = count+65;
    sort(arr,arr+26,greater<>());
    if(arr[0]==arr[1]){
        cout<<"?";
    }else{
        cout<<ch;
    }
    return 0;
}