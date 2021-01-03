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

int GCD(int a,int b){
    if(b==0){
        return a;
    }else{
        return GCD(b,a%b);
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);  
    int up1,up2,down1,down2;
    cin>>up1>>down1>>up2>>down2;
    //down1 과 down2의 최소공배수
    int L = (down1*down2)/GCD(down1,down2);

    int newUp1 = (L/down1)*up1;
    int newUp2 = (L/down2)*up2;
    int finalUp1 = newUp1 + newUp2;

    if(GCD(finalUp1,L)==1){
        cout<<finalUp1<<" "<<L;
    }else{
        int newL = L/GCD(finalUp1,L);
        int newUp = finalUp1/GCD(finalUp1,L);
        cout<<newUp<<" "<<newL;
    }
    
    
    return 0;
}