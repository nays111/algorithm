#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(){
    long long a,m,d,n;
    cin>>a>>m>>d>>n;
    for(int i=1;i<n;i++){
        a*=m;
        a+=d;
    }
    cout<<a;
    
}
