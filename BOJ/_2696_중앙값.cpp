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
    
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int m;
        cin>>m;

        if(m%2==1){
            cout<<(m+1)/2<<'\n';
        }else{
            cout<<m/2<<'\n';
        }

        priority_queue<int> pq;
        queue<int> temp;

        for(int j=1;j<=m;j++){
            int num;
            cin>>num;
            if(j%2==1){
                pq.push(num);
                for(int k=0;k<j/2;k++){
                    temp.push(pq.top());
                    pq.pop();
                }
                cout<<pq.top()<<" ";
                while(!temp.empty()){
                    pq.push(temp.front());
                    temp.pop();
                }
            }else{
                pq.push(num);
            }
        }
        cout<<'\n';
    }
    
    return 0;
}