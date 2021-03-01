#include <string>
#include <iostream>
#include <vector>

using namespace std;
int answer = 9;
void dfs(int index,int n,int target,int result){
    
    if(index>8){
        return;
    }
    if(result ==target){
        answer = min(answer,index);
    }
    int newN = 0;
    for(int i=0;i<8;i++){
        newN = newN*10+n;
        dfs(index+i+1,n,target,result+newN);
        dfs(index+i+1,n,target,result-newN);
        if(result!=0){
            dfs(index+i+1,n,target,result*newN);
            dfs(index+i+1,n,target,result/newN);
        }
    }

    
}


int solution(int N, int number) {
    dfs(0,N,number,0);
    cout<<answer;
    if(answer==9){
        answer = -1;
    }
    return answer;
}