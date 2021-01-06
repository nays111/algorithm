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
struct baseball{
    string str;
    int strike;
    int ball;
};
vector<baseball> v;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        baseball b;
        cin>>b.str>>b.strike>>b.ball;
        v.push_back(b);
    }
    int count[1000]={0,};

    for(int i=123;i<=987;i++){
        string str = to_string(i);
        
        if(str[2]=='0' || str[1]=='0' || str[0]=='0'
        || str[2]==str[1] || str[1]==str[0] || str[2]==str[0]){
            continue;
        }
        for(int j=0;j<n;j++){
            int tempStrike = 0;
            int tempBall = 0;
            for(int k=0;k<3;k++){
                if(v[j].str[k]==str[k]){
                    tempStrike++;
                }
                if(str[k]==v[j].str[(k+1)%3] || str[k]==v[j].str[(k+2)%3]){
                    tempBall++;
                }
            }
            if(tempStrike == v[j].strike && tempBall == v[j].ball){
                count[i]++;
            }
        }
        //  cout<<i<<":"<<count[i]<<'\n';
    }
    int max = 0;
    for(int i=0;i<1000;i++){
        if(max<count[i]){
            max = count[i];
        }
    }
    int answer=0;
    for(int i=0;i<1000;i++){
        if(max==count[i]){
            answer++;
        }
    }
    
    cout<<answer;
    return 0;

}