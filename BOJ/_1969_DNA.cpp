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

    int n,m;
    cin>>n>>m;
    int arr[1001][4]={0,};
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<str.size();j++){
            if(str[j]=='A'){
                arr[j][0]++;
            }else if(str[j]=='C'){
                arr[j][1]++;
            }else if(str[j]=='G'){
                arr[j][2]++;
            }else if(str[j]=='T'){
                arr[j][3]++;
            }
        }   
    }

    string answer = "";
    int result = 0;
    for(int i=0;i<m;i++){
        int max = 0;
        int index = 0;
        for(int j=0;j<4;j++){
            if(arr[i][j]>max){
                max = arr[i][j];
                index = j;
            }
        }
        result = result + (n-max);
        if(index==0){
            answer+='A';
        }else if(index==1){
            answer+='C';
        }else if(index ==2){
            answer+='G';
        }else if(index==3){
            answer+='T';
        }

    }
    
    cout<<answer<<'\n'<<result;
    
    


    return 0;

}