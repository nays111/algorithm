#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int arr[10001][10001];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    //초기값 설정
    int num=1;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++){
            arr[i][j] = num;
            num++;
        }
    }
    
 
    for(int i=0;i<queries.size();i++){
        int startY = queries[i][0];
        int startX = queries[i][1];
        int endY = queries[i][2];
        int endX = queries[i][3];
        
        
        int index = 0;
        int temp;
        
        vector<int> v;
        //아래로
        while(1){
            temp = arr[startY+index+1][startX];
            v.push_back(temp);
            arr[startY+index+1][startX] = arr[startY+index][startX];
            arr[startY+index][startX] = temp;
            
            if(startY+index+1 == endY){
                break;
            }
            index++;
            
        }
        //오른쪽으로
        index = 0;
        while(1){
            temp = arr[endY][startX+index+1];
            v.push_back(temp);
            arr[endY][startX+index+1] = arr[endY][startX+index];
            arr[endY][startX+index] = temp;
            
            if(startX+index+1 == endX){
                break;
            }
            index++;
        }
        //위로
        index = 0;
        while(1){
            temp = arr[endY-index-1][endX];
            v.push_back(temp);
            arr[endY-index-1][endX] = arr[endY-index][endX];
            arr[endY-index][endX] = temp;
            if(endY-index-1 == startY){
                break;
            }
            index++;
        }
        
        index = 0;
        //왼쪽으로
        while(1){
            temp = arr[startY][endX-index-1];
            v.push_back(temp);
            arr[startY][endX-index-1] = arr[startY][endX-index];
            arr[startY][endX-index] = temp;
            if(endX-index-1 == startX){
                break;
            }
            index++;
        }
        v.pop_back();
        
        //하나 더 스왑되는거 되돌리기
        temp = arr[startY][startX];
        v.push_back(temp);
        arr[startY][startX] = arr[startY][startX+1];
        arr[startY][startX+1] = temp;
        
        sort(v.begin(),v.end());
        answer.push_back(v[0]);

    }
    
    
    return answer;
}