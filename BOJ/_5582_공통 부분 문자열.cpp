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
    string str1;
    string str2;
    cin>>str1>>str2;
    int dp[4001][4001];
    int maxLength = 0;
    for(int i=0;i<str1.size();i++){
        for(int j=0;j<str2.size();j++){
            if(str1[i]==str2[j]){
                dp[i][j]++;
                if(i>0 && j>0){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                maxLength = max(maxLength,dp[i][j]);
            }
        }
    }
    cout<<maxLength;
    
    return 0;
}