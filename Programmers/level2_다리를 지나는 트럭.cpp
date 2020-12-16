#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0; //경과 시간
    queue<int> q;
    int sum=0;
    int index=0;
    while(1){
        if(index==truck_weights.size()){//대기트럭이 없을때
            answer+=bridge_length; //아직 다리를 건너는 트럭이 있으므로 다리 건너는 시간만큼은 더해줌
            break;
        }
        answer++;//시간 증가
        if(q.size()==bridge_length){
            //q에 우리는 트럭외에 0을 매초마다 쌓고있으니 q의 길이와 다리의 길이가 같아지면 pop
            sum-=q.front();
            q.pop();
        }
        if(sum+truck_weights[index]<=weight){
            q.push(truck_weights[index]);
            sum+=truck_weights[index];
            index++;
            
        }else{
            q.push(0);
        }
    }
    return answer;
}