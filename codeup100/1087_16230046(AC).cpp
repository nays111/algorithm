#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(){
    int a;
    cin>>a;
    int sum = 0;
    for(int i=1;i<=a;i++){
        sum+=i;
        if(sum>=a){
            cout<<sum;
            break;
        }
    }
}
