#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a;
    int tmp[23]={0,};
    for(int i=0;i<n;i++){
        cin>>a;
        tmp[a-1]+=1;
    }
    for(int i=0;i<23;i++){
        cout<<tmp[i]<<" ";
    }
    
    
}
