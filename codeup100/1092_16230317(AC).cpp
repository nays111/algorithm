#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(){
    int a,b,c,day=1;
    cin>>a>>b>>c;
    while(true){
        if(day%a==0 and day%b==0 and day%c==0){cout<<day; break;}
        else{day+=1;}
    }
}
