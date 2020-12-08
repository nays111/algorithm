#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    int l;
    for(int i=0;i<n;i++){
        cin>>l;
        arr[i]=l;
    }
    for(int j=n-1;j>=0;j--){
        cout<<arr[j]<<" ";
    }
    
}
