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
void hanoi(int num,int from, int by, int to){
    if(num==1){
        cout<<from<<" "<<to<<'\n';
    }else{
        hanoi(num-1,from,to,by);
        cout<<from<<" "<<to<<'\n';
        hanoi(num-1,by,from,to);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
  
    cin>>n;
    cout<<(1 << n) - 1 <<endl;
    hanoi(n,1,2,3);


    return 0;

}