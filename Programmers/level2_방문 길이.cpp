#include <string>
#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    bool visit[11][11][11][11];
    int fromY=0;
    int fromX=0;
    int toY;
    int toX;
    for(int i=0;i<dirs.size();i++){
        if(dirs[i]=='U'){
            toY = fromY + 1;
            toX = fromX;
        }else if(dirs[i]=='L'){
            toY = fromY;
            toX = fromX - 1;
        }else if(dirs[i]=='R'){
            toY = fromY;
            toX = fromX + 1;
        }else if(dirs[i]=='D'){
            toY = fromY-1;
            toX = fromX;
        }
        if(toY>5 || toX>5|| toY<-5 || toX<-5){
            continue;
        }
        if(visit[toY][toX][fromY][fromX]==false){
            visit[toY][toX][fromY][fromX]=true;
            visit[fromY][fromX][toY][toX]=true;
            answer++;
        }
        fromY = toY;
        fromX = toX;

    }
    return answer;
}