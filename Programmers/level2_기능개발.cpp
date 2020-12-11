#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> temp;
    for(int i=0;i<progresses.size();i++){
        int t = (100-progresses[i])%speeds[i];
        if(t==0){
            temp.push_back((100-progresses[i])/speeds[i]);
        }else{
            temp.push_back((100-progresses[i])/speeds[i]+1);
        }
    }
    int count = 0;
    int max = temp[0];
    for(int i=0;i<temp.size();i++){
        if(max < temp[i]){
            answer.push_back(count);
            count = 1;
            max = temp[i];
        }else{
            count++;
        }
        
        if(i==temp.size()-1){
            answer.push_back(count);
        }
    }
    return answer;
}