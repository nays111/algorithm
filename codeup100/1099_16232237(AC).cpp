#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int arr[10][10];
    int x=1,y=1;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>arr[i][j];
        }
    }
    while(true){
        if(arr[x][y]==2){
            arr[x][y]=9;
            break;
        }else if(arr[x][y]==0){
            arr[x][y]=9;//지나간 흔적 남기기
            y+=1;
        }else if(arr[x][y]==1){
            x+=1;
            y-=1;
        }else{break;}
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}
