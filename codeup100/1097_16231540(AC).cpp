#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int arr[19][19];
    int n,x,y;
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            cin >> arr[i][j];
        }
    }
    cin>> n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        for(int j=0;j<19;j++){
            
            arr[x-1][j] = not arr[x-1][j];
            arr[j][y-1] =not arr[j][y-1];
        }
    }
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}
