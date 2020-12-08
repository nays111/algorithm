#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(){
    int a,d,n;
    cin>>a>>d>>n;
    for(int i=1;i<n;i++){
        a+=d;
    }
    cout<<a;
    
}
