#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(){
    float w,h,b;
    cin>>w>>h>>b;
    printf("%.2f MB",(w*h*b)/(8*1024*1024));
}
