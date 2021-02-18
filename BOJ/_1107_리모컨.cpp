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
/*
리모콘 버튼을 누르는 횟수를 최소화
5457 (6,7,8) 고장
5435+++54--5455++는 절대 정답 x
+,-를 누르다가 숫자 버튼을 누르는 순간 그 전까지 입력한 것은 의미 없어진다.
5455--++++ 절대 정답 x
중복이 발생하는 경우 절대 최소 불가

1. 이동할 채널 C를 정한다.
2. C에 포함되어있는 숫자 중에 고장난 버튼이 있는지 확인한다.
- 수를 10으로 계속해서 나누면서 하나씩 검사하는 방법
- 수를 문자열로 바꾼 다음, 한글자씩 검사하는 방법
3. 고장난 버튼이 포함되어 있지 않다면 |C-N|을 계산하 +나 -를 몇번 눌러야하는지를 계산

*/


bool broken[10]; //고장난 버튼


int func(int n){
    if(n==0){
        if(broken[0]==true){
            return 0;
        }else{
            return 1;//0번으로 이동하려는데 안고장났으면 한번 클릭으로 이동 가능
        }
    }

    int counts=0;
    while(n>0){
        if(broken[n%10]==true){
            return 0;
        }
        n=n/10;
        counts++;
    }
    return counts;
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,m;  
    cin>>n>>m;
    
    //고장난 버튼 입력
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        broken[a]=true;
    }
    int result = abs(n-100);//+,- 클릭만으로 이동하는 경우
    for(int i=0;i<=1000000;i++){
        int temp = i;
        int len = func(temp);//i번까지는 숫자 클릭으로 이동
        if(len>0){
            int press = abs(temp-n);//목표지점까지 +,-만으로 이동하는 경우 (대신, i번까지는 이미 번호클릭으로 이동되어있음)
            result = min(result,press+len);
        }

    }
    cout<<result;
    

    

    return 0;
}