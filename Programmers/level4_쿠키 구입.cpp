#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    
    
    for(int i=0;i<cookie.size()-1;i++){
        int firstIndex = i;
        int secondIndex = i + 1;
        
        int firstSum = cookie[firstIndex];
        int secondSum = cookie[secondIndex];
        while(1){
            if(firstSum == secondSum){
                answer = max(answer,firstSum);
            }
            
            if(firstIndex > 0 && firstSum <= secondSum){
                
                firstIndex--;
                firstSum += cookie[firstIndex];
                
            }else if(secondIndex < cookie.size()-1 && firstSum >= secondSum){
                
                secondIndex++;
                secondSum += cookie[secondIndex];
                
            }else{
                
                break;
                
            }
        }
    }
    
    return answer;
}