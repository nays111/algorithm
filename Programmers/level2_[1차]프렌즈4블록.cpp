#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


//1. board[0][0]~board[m-1][n-1]까지 탐색
//2. board[i][j],board[i+1][j], board[i][j+1],board[i+1][j+1] 을 검사
//3. 만약 네개 값이 모두 일치한다면 bool check 값을 true로 교체
//4. check 배열 중에 true인것 개수 count
//5. true인곳을 채워넣음
//6. 

using namespace std;
char arr[31][31];
bool check[31][31]={false,};


//지울 수 있는 2x2배열이 몇개있는지 count
int count22(int m,int n){
    int cnt = 0;
    for(int i=0;i<m-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr[i][j]!='0'&& (arr[i][j]==arr[i+1][j]) && (arr[i][j]==arr[i][j+1]) && (arr[i][j]==arr[i+1][j+1])){
                check[i][j]=true;
                check[i+1][j]=true;
                check[i][j+1]=true;
                check[i+1][j+1]=true;
            }
        }
    }
               
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(check[i][j]==true){
                arr[i][j]='0'; //빈칸으로 변경
                cnt++;
            }
        }
    }
    return cnt;              
}

//아래로 move하는 함수
void moveDown(int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]=='0'){
                for(int k=i;k>0;k--){
                    arr[k][j]=arr[k-1][j];
                    arr[k-1][j]='0';
                }
            }
        }
    }
}


//check 초기화               
void init(int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            check[i][j]=false;
        }
    }
}



int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            arr[i][j] = board[i][j];
        }
    }
    
    while(1){
        int t = count22(m,n);
        if(t==0){//더 이상 2x2로 지울게 없으면 탈출
            break;
        }
        answer = answer+t;
        moveDown(m,n);
        print(m,n);
        init(m,n);
        
    }
    
    
    
    return answer;
}