#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 1234;
    int dp[1001][1001];
    
    
    for(int i=1;i<board.size();i++){
        for(int j=1;j<board[i].size();j++){
            if(board[i-1][j-1]!=0 && board[i-1][j]!=0 && board[i][j-1]!=0 && board[i][j]!=0){
                board[i][j] = min(board[i-1][j-1],min(board[i-1][j],board[i][j-1]))+1;
            }
        }
    }
    int len=0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            len = max(len,board[i][j]);
        }
    }
    
    answer = len*len;
    

    

    return answer;
}