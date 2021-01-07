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
    string str;
    getline(cin,str);

  
    for(int i=0;i<str.size();i++){
        if(str[i]-'\0'>=65 && str[i]-'\0'<=90){ //대문자인 경우
            if(str[i]+13>90){
                str[i] =str[i] + 13 -26;;
            }else{
                str[i] = str[i] + 13;
            }
            
        }else if(str[i]-'\0'>=97 && str[i]-'\0'<=122){ //소문자인 경우
            if(str[i]+13>122){
                str[i] = str[i] + 13 -26;
            }else{
                str[i] = str[i] + 13;
            }
        }
    }
    cout<<str;
    
    return 0;

}