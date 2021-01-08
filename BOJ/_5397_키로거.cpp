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
        string str;
        cin>>str;
        stack<char> left;
        stack<char> right;
        for(int i=0;i<str.size();i++){
            if(str[i]=='<'){
                if(!left.empty()){
                    right.push(left.top());
                    left.pop();
                }
            }else if(str[i]=='>'){
                if(!right.empty()){
                    left.push(right.top());
                    right.pop();
                }

            }else if(str[i]=='-'){
                if(!left.empty()){
                    left.pop();
                }
            }else{
                left.push(str[i]);
            }
        }

        while(!left.empty()){
            right.push(left.top());
            left.pop();
        }
        while(!right.empty()){
            cout<<right.top();
            right.pop();
        }
        cout<<'\n';
    }
    

    return 0;
}