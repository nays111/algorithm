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
    for(int i=0;i<n;i++){
        int x1,y1,r1,x2,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        double dist = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
        int answer;
        if(x1==x2 && y1==y2 && r1==r2){
            answer = -1; //원 두개가 완전히 겹칠때
        }else if(dist<r1+r2 && dist>abs(r1-r2)){
            answer = 2; //원 두개가 만나는 점이 두개일때
        }else if(dist == r1+r2){
            answer = 1; //원 바깥쪽이 겹칠때
        }else if(dist == abs(r1-r2)){
            answer = 1; //원안에 원이 있는데 겹칠때
        }else if(dist > r1+r2){
            answer = 0; //그냥 원이 따로따로 있을때
        }else if(dist < abs(r1-r2)){
            answer = 0; //원 안에 원이 있을 때
        }
        cout<<answer<<'\n';
    }
    

    
    return 0;

}