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
int n;
int answer = 0;
int arr[15];

//여기 퀸을 놔도 괜찮을까?
bool possible(int row){
    for(int i=1;i<row;i++){
        if(arr[i]==arr[row]){
            return false;
        }
        if(abs(arr[i]-arr[row])==abs(i-row)){
            return false;
        }
    }
    return true;
}

void dfs(int row){
    if(row==n){ //검사 끝난시점
        answer++;
    }else{
        for(int i=1;i<=n;i++){
            //8x8이면 1부터 8까지 검사
            arr[row+1] = i;//(2,1), (2,2), (2,3) , (2,4) ....중 한군데에 퀸 놓아보면서 루프 돌면서 일단 퀸을 놓아봄
            if(possible(row+1)==true){
                dfs(row+1); //만약 퀸 놓을 수 있는 곳이면 재귀
            }else{
                arr[row+1]=0;//퀸 경로에 잇으니깐 다시 되돌려
            }            
        }
    }
    arr[row]=0; //실패했으니깐 퀸 없애기

    
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        arr[1] = i; 
        dfs(1);
        // 1행 1열에 퀸을 놓았을 경우
        // 1행 2열에 놓았을 경우~~~
    }
    cout<<answer;
    
    return 0;

}