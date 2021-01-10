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

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    //기타줄은 총 6개
    stack<int> guitar[7];

    int n,p; //p는 필요없는 수인듯?
    cin>>n>>p;
    int answer = 0;
    for(int i=0;i<n;i++){
        int stackIndex, buttonIndex;
        cin>>stackIndex>>buttonIndex;

        if(guitar[stackIndex].empty()){ //ok
            guitar[stackIndex].push(buttonIndex);
            answer++;
        }else{
            if(guitar[stackIndex].top()==buttonIndex){ //ok
                continue;
            }else if(guitar[stackIndex].top()<buttonIndex){ //ok
                guitar[stackIndex].push(buttonIndex);
                answer++;
            }else if(guitar[stackIndex].top()>buttonIndex){
                while(!guitar[stackIndex].empty() && guitar[stackIndex].top() > buttonIndex){
                    guitar[stackIndex].pop();                    
                    answer++;
                }
            
                if(!guitar[stackIndex].empty()&&guitar[stackIndex].top()==buttonIndex){
                    continue;
                }else{
                    guitar[stackIndex].push(buttonIndex);
                    answer++;  
                }
                            
            }
        }
    }
    cout<<answer;

    return 0;
}