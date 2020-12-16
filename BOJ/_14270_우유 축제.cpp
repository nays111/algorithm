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

    int N;
    cin>>N;
    int count;
    stack <int> st;
    int arr[3]={0,1,2};
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        if(st.empty() && a==0){
            st.push(a);       
        }else if(!st.empty() && st.top()==arr[(a+2)%3]){
            st.push(a);
        }
        cout<<st.top()<<endl;
    }
    cout<<st.size();

    return 0;
}