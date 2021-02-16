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
    string target;
    cin>>target;
    int arr[26]={0,};
    for(int i=0;i<target.size();i++){
        arr[target[i]-65]++;
    }

    int answer = 0;


    for(int i=0;i<n-1;i++){
        string str;
        cin>>str;
        int strArr[26]={0,};
        for(int j=0;j<str.size();j++){
            strArr[str[j]-65]++;
        }
        bool flag = true;
        int fault = 0;
        int fault2=0;
        for(int j=0;j<26;j++){
            if(strArr[j]==arr[j]){
                continue;
            }
            if(abs(strArr[j]-arr[j])>1){
                flag = false;
                break;
            }else if(strArr[j]>arr[j]){
                fault++;
            }else if(strArr[j]<arr[j]){
                fault2++;
            }

            if(fault>1 || fault2>1){
                flag=false;
                break;
            }
        }

        if(flag==true){
            answer++;
        }
        






    }
    cout<<answer;
    
    return 0;
}