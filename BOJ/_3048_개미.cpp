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
struct ants{
    int dir;
    char alphabet;
};
ants ant[27];
void swap(int a,int b){
    ants temp = ant[a];
    ant[a]=ant[b];
    ant[b]=temp;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n1,n2;
    char ch;
    int time;
    
    cin>>n1>>n2;
    for(int i=0;i<n1;i++){
        cin>>ch;
        ant[n1-1-i] = {0,ch};//오른쪽 방향은 0 CBA 이렇게 삽입
    }
    for(int i=n1;i<=n1+n2-1;i++){
        cin>>ch;
        ant[i] = {1,ch}; //왼쪽 방향은 1 DEF 이렇게 삽입
    }
    cin>>time;
    for(int i=0;i<time;i++){
        //만약 서로 다른방향에서 마주치면 swap
        for(int j=0;j<n1+n2-1;j++){
            if(ant[j].dir==0 && ant[j].dir!=ant[j+1].dir){
                swap(j,j+1);
                j++;
            }
        }
    }
    for(int i=0;i<n1+n2;i++){
        cout<<ant[i].alphabet;
    }

    return 0;
}