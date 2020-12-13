#include <string>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

int solution(int n) {
    int num = bitset<20>(n).count();
    
    cout<<num;
    int i=n+1;
    while (bitset<20>(i).count() != num){
        i++;
    }
    return i;
}