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
    // int hansuCount = 0;
    // for(int i=10;i<=n;i++){
    //     vector<int> v;
    //     while(i!=0){
    //         int t = i%10;
    //         v.push_back(t);
    //         i=i/10;
    //     }
    //     int x = v[0]-v[1];
        
    //     int count = 1;
    //     for(int j=2;j<=v.size();j++){
    //         if(x==v[j]-v[j-1]){
    //             count++;
    //         }
    //     }
    //     if(count==v.size()){
    //         hansuCount++;
    //     }
    // }
    // cout<<hansuCount;
    int count = 0;
    for(int i=1;i<=n;i++){
        string str = to_string(i);
        if(str.size()==1){
            count++;
        }else{
            int x = (str[0]-'\0') - (str[1]-'\0');
            int a=0;
            for(int j=0;j<str.size()-1;j++){
                if((str[j]-'\0')-(str[j+1]-'\0')==x){
                    a++;
                }
            }
            if(a==str.size()-1){
                count++;
            }
        }
    }
    cout<<count;
    

    return 0;
}