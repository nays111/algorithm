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
const int MAX = 1000000;
int prime[MAX];//소수들만 들어있음
bool isCheck[MAX+1];
int z;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    
    for(int i=2;i<=MAX;i++){
        if(isCheck[i]==false){//i에 대해서 아직 검사를 안했으면(아직 삭제되지않았다는 뜻)
            prime[z++] = i; //가장 먼저 나온 수는 소수이고 나머지는 해당 수에 배수이므로 삭제해야함
            for(int j=i+i;j<=MAX;j+=i){ //i번째값은 소수이므로 냅두고 i+i서부터 진행
                isCheck[j] = true; //소수 아닌건 true, 소수인건 false
                //ex) i=2
                //4=2*2
                //6=2*3
                // ...
            }

        }
    }
    
    while(1){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        for(int i=1;i<z;i++){//prime[0] 은 2이니깐 빼고 시작하기 위해 1부터
            if(isCheck[n-prime[i]]==false){ //가장 작은거부터 출력해야하니깐
                //n-b = a에서
                //a도 소수라면
                cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
                break;
            }

        }
        
    }
    return 0;
}