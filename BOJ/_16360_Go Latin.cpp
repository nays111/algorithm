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
        string str;
        cin>>str;
        int size = str.size();
        if(str[size-1]=='a'){
            str= str+"s";
        }else if(str[size-1]=='i' || str[size-1]=='y'){
            str[size-1]='i';
            str = str+"os";
        }else if(str[size-1]=='l'){
            str = str+"es";
        }else if(str[size-1]=='n' ){
            str[size - 1] = 'a'; 
            str =str+ "nes";
        }else if(str[size-2]=='n'&& str[size-1]=='e'){
            str[size - 2] = 'a'; 
            str[size - 1] = 'n'; 
            str =str+ "es";
        }else if(str[size-1]=='o'){
            str=str+"s";
        }else if(str[size-1]=='r'){
            str=str+"es";
        }else if(str[size-1]=='t'){
            str=str+"as";
        }else if(str[size-1]=='u'){
            str=str+"s";
        }else if(str[size-1]=='v'){
            str=str+"es";
        }else if(str[size-1]=='w'){
            str=str+"as";
        }else{
            str=str+"us";
        }
        cout<<str<<"\n";
    }
    return 0;
}