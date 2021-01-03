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
    int answer = 0;

    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        bool flag = true;
        for(int j=0;j<str.size()-1;j++){
            if(str[j]!=str[j+1]){
                //한 칸 건너뛰어서 또 같은 게 나오면 문제
                for(int k=j+2;k<str.size();k++){//AABA
                    if(str[k]==str[j]){
                        flag = false;
                    }
                }
            }
        }
        if(str.size()==1){
            flag = true;
        }
        if(flag==true){
            answer++;
        }
    }
    cout<<answer;
    return 0;
}