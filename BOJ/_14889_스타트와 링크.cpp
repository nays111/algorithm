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
int n;
bool visit[22];
int arr[22][22];
int answer = 987654321;

void func(int cnt,int index){
    if(cnt==n/2){
        int start=0;
        int link=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(visit[i]==true && visit[j]==true){
                    start = start + arr[i][j] + arr[j][i];
                }
                if(visit[i]==false && visit[j]==false){
                    link = link + arr[i][j] + arr[j][i];
                }
            }
        }
        answer = min(answer,abs(start-link));
        return;
    }else{
        for(int i=0;i<n;i++){
            if(visit[i]==false && i>index){
                visit[i]=true;
                func(cnt+1,i);
                visit[i]=false;       
            }
        }
    }

}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    func(0,-1);
    cout<<answer;

    return 0;
    
}