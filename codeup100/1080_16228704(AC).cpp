#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(){
    int sum;
    int i=1;
    int n;
    cin>>n;
    while(true){
    
        sum+=i;
        if(sum>=n){
            cout<<i;
            break;
        }
        i++;

    }
}
