#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
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
    sort(arr,arr+n);
    cout<<arr[0];
    
}
