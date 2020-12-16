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
vector<pair<int,int>> v;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int L,P,V;
    int index = 0;
    while(1){
        cin>>L>>P>>V;
        if(L==0 && P==0 && V==0){
            break;
        }
        int option=0;
        if((V%P)>L){
            option = L;
        }else{
            option = V%P;
        }
        int count = (V/P)*L+option ;
        index++;
        cout<<"Case "<<index<<": "<<count<<endl;
    }
    return 0;
}