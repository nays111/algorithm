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
int check(vector<string> &candy){
    int len = 1;
    for(int i=0;i<candy.size();i++){
        int count = 1;
        for(int j=1;j<candy.size();j++){
            if(candy[i][j]==candy[i][j-1]){ 
                count++;
            }else{
                count = 1;
            }
            if(count>len){
                len = count;
            }
        }//가로 검사
        count = 1;
        for(int j=1;j<candy.size();j++){
            if(candy[j][i]==candy[j-1][i]){
                count++;
            }else{
                count = 1;
            }
            if(count>len){
                len = count;
            }
        }//세로 검사
    }
    return len;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);   
    int n;
    cin>>n;
    vector <string> candy(n);
    //char candy[n][n];
    for(int i=0;i<n;i++){
        cin>>candy[i];
    }
    int max = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j+1<n){//오른쪽으로 검사
                swap(candy[i][j],candy[i][j+1]);
                int len = check(candy);
                if(len>max){
                    max = len;
                }
                swap(candy[i][j],candy[i][j+1]);//다시 원래대로 돌리는 것
            }
            if(i+1<n){//아래쪽으로 검사
                swap(candy[i][j],candy[i+1][j]);
                int len = check(candy);
                if(len>max){
                    max = len;
                }
                swap(candy[i][j],candy[i+1][j]);//다시 원래대로 돌리는 것
            }
        }
    }
    cout <<max;

    return 0;
}