#include <vector>
#include <iostream>

using namespace std;

int arr[101][101]={0};
bool visit[101][101]={false};
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

int dfs(int y,int x,int index,int m,int n,int cnt){
    
    visit[y][x] = true;
    
    for(int i=0;i<4;i++){
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        if(nextY>=m || nextX>=n || nextY<0 || nextX<0){
            continue;
        }
        if(visit[nextY][nextX]==false && arr[nextY][nextX]==index){
            cnt =  dfs(nextY,nextX,index,m,n,cnt+1);
            
        }
    }
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=picture[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            visit[i][j]=false;
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]==false && arr[i][j]!=0){
                max_size_of_one_area = max(max_size_of_one_area,dfs(i,j,arr[i][j],m,n,1));
                cout<<i<<" "<<j<<" "<<max_size_of_one_area<<'\n';
                number_of_area++; //연결요소의 개수 count
            }
        }
    }
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}