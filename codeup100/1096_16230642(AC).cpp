#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[19][19]={0,};
   
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        arr[a-1][b-1]=1;
    }
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
