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

bool result[21];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        int num;
        cin>>str;
        if(str=="add"){
            cin>>num;
            result[num]=true;
        }else if(str=="check"){
            cin>>num;
            if(result[num]==false){
                cout<<0<<'\n';
            }else{
                cout<<1<<'\n';
            }
        }else if(str=="remove"){
            cin>>num;
            result[num]=false;
        }else if(str=="toggle"){
            cin>>num;
            if(result[num]==true){
                result[num]=false;
            }else{
                result[num]=true;
            }
        }else if(str=="all"){
            memset(result,true,sizeof(result));
        }else if(str=="empty"){
            memset(result,false,sizeof(result));
        }
    }
    

    return 0;

}


