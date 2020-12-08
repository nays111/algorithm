#include <iostream>
using namespace std;
int main(){
    int a,b,c, cnt=0;
    cin >> a>>b>>c;
    for(int i=0;i<a;i++){
        for(int k=0;k<b;k++){
            for(int q=0;q<c;q++){
                printf("%d %d %d\n",i,k,q);
                cnt +=1;
            }
        }
    }
    cout<<cnt;
}
