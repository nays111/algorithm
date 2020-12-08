#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(){
    float h,b,c,s;
    float num;
    cin>>h>>b>>c>>s;
    num = (h*b*c*s)/(8*1024*1024);
    printf("%.1f MB",num);
}
