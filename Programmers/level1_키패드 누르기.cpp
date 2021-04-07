#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftHandLoc = 10; //10 -> *
    int rightHandLoc = 12; //12 -> #
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]==0){
            numbers[i]=11; //11 -> 0
        }
    }
    
    
    
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7){
            answer=answer+'L';
            leftHandLoc = numbers[i];
        }
        if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9){
            answer=answer+'R';
            rightHandLoc = numbers[i];
        }
        
        if(numbers[i]==2 || numbers[i]==5 || numbers[i]==8 || numbers[i]==11){

            int leftHandDist = abs(numbers[i]-leftHandLoc)/3 + abs(numbers[i]-leftHandLoc)%3;
            int rightHandDist = abs(numbers[i]-rightHandLoc)/3 + abs(numbers[i]-rightHandLoc)%3;
            //cout<<leftHandDist<<" "<<rightHandDist<<'\n';
            
            
            if(leftHandDist == rightHandDist){
                if(hand=="left"){
                    answer = answer + 'L';
                    leftHandLoc = numbers[i];
                }else if(hand=="right"){
                    answer = answer + 'R';
                    rightHandLoc = numbers[i];
                }
                continue;
            }
            
            int dist = min(leftHandDist,rightHandDist);
            if(leftHandDist==dist){
                answer = answer + 'L';
                leftHandLoc = numbers[i];
            }else if(rightHandDist==dist){
                answer = answer + 'R';
                rightHandLoc = numbers[i];
            }
            
        }
    }
    
    
    return answer;
}