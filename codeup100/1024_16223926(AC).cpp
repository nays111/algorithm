#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    char a[21];
    cin >> a;
    for(int i=0;a[i]!=0;i++){
        cout<<"'"<<a[i]<<"'"<<endl;
    }
}
