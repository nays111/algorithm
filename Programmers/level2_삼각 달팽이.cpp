#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int arr[1001][1001];
      
    int dir = 0; //0 down, 1 right, 2 up
    int cnt = n;
    int yPoint = 0;
    int xPoint = 0;
    int startPoint = 1;

    
    
    for(int i=0;i<n;i++){
        
        
        if(dir==0){ //  아래로
            for(int j=i;j<n;j++){
                arr[yPoint][xPoint] = startPoint;
                startPoint++;
                yPoint++;
            }
            yPoint--;
            xPoint++;
            dir=1;
        }else if(dir==1){ //오른쪽으로
            for(int j=i;j<n;j++){
                arr[yPoint][xPoint] = startPoint;
                startPoint++;
                xPoint ++;
            }
            xPoint--;
            dir=2;
        }else if(dir==2){ //왼쪽으로
            for(int j=i;j<n;j++){
                yPoint--;
                xPoint--;
                arr[yPoint][xPoint] = startPoint;

                startPoint++;          
            }
            dir = 0;
            yPoint++;

        }

    }
    

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                answer.push_back(arr[i][j]);
            }
        }
    }
    
    return answer;
}