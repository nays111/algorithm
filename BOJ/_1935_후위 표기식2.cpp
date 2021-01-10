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
    string str;
    double answer = 0;
    stack<double> st;
    map<char,double> mp;
    cin>>n>>str;
    char key='A';
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        mp.insert(make_pair(key,value));
        key++;
    }

    for(int i=0;i<str.size();i++){
        if(str[i]-'\0'>=65 && str[i]-'\0'<=90){
            st.push(mp[str[i]]);
        }else{
            double top1 = st.top();
            st.pop();
            double top2 = st.top();
            st.pop();
            if(str[i]=='+'){ 
                st.push(top2+top1);
            }else if(str[i]=='-'){
                st.push(top2-top1);
            }else if(str[i]=='*'){
                st.push(top2*top1);
            }else if(str[i]=='/'){
                st.push(top2/top1);
            }
        }
    }
    answer = st.top();
    cout<<fixed;
    cout.precision(2);
    cout<<answer;

    return 0;
}