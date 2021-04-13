#include <iostream>
#include <math.h>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    while(1){
     
        
        if(a%2==1){
            a++;
        }
        a=a/2;
        if(b%2==1){
            b++;
        }
        b=b/2;
        if(a==b){
            break;
        }
        //cout<<a<<b;
        answer++;
        
    }

    return answer;
}