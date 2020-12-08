#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;
    int arr[100][100]={0,};
    int n;
    cin>>n;
    int l,d,x1,y1;
    for(int i=0;i<n;i++){
        cin>>l>>d>>x1>>y1;
        for(int j=0;j<l;j++){
            if(d==0){
                arr[x1-1][y1-1+j]=1;
            }else{
                arr[x1-1+j][y1-1]=1;
            }
        }
    }
    
    for(int k=0;k<x;k++){
        for(int w=0;w<y;w++){
            cout<<arr[k][w]<<" ";
        }
        cout<<endl;
    }

}
