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
    //d(75) = 75 + 7 + 5 = 87
    //d(n) = n+n/10+n%10
    //n은 d(n)의 생성자
    //생성자가 없는 숫자 = 셀프 넘버
    //셀프 넘버를 구하라
    int t=1;
    vector<int> v;
    while(1){
        //n가지고 d(n)으로 만들어지지 않는 것을 쭉 출력
        //10000넘어가면 break
        int n = t;
        int createNumber = 0;
        while(n>0){
            createNumber +=n%10;
            n=n/10;    
        }
        createNumber = createNumber + t; 
        //cout<<createNumber<<"\n";
        //생성자를 미리 다 넣어두기
        v.push_back(createNumber); //createNumber에 나오지않는수를 뽑아내야함
        //1~10000 중에 createNumber를 제외

        int k=1;
        t++;
        if(t==10000){
            break;
        }
    }
    for(int i=1;i<10000;i++){
        int count = 0;
        for(int j=0;j<v.size();j++){
            
            if(i==v[j]){
                count++;
            }
        }
        if(count==0){
            cout<<i<<'\n';
        }
    }

    

    return 0;
}