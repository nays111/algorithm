#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
#include <functional>
using namespace std;
string whiteFist[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string blackFist[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};
string arr[50];
int checkCountWithBlackFirst(int y,int x){
    int count = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[i+y][j+x]!=blackFist[i][j]){
                count++;
            }
        }
    }
    return count;
}
int checkCountWithWhiteFirst(int y,int x){
    int count = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[i+y][j+x]!=whiteFist[i][j]){
                count++;
            }
        }
    }
    return count;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int x,y;
    cin>>x>>y;
    for(int i=0;i<x;i++){
        cin>>arr[i];
    }
    int mini = x*y;
    for(int i=0;i<=x-8;i++){
        for(int j=0;j<=y-8;j++){
            mini = min(mini,min(checkCountWithBlackFirst(i,j),checkCountWithWhiteFirst(i,j)));
        }
    }
    cout<<mini;
    
    return 0;

}