#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    pair<string,int> p;
    for(int i=0;i<m.size();i++){
        if(m[i]=='#'){
            m[i-1]= m[i-1]-'A'+'a';
            m.erase(i,1);
        }
    }
    
    for(int i=0;i<musicinfos.size();i++){
        string musicInfo = musicinfos[i];
        for(int j=0;j<musicInfo.size();j++){
            if(musicInfo[j]=='#'){
                musicInfo[j-1]= musicInfo[j-1]-'A'+'a';
                musicInfo.erase(j,1);
            }
        }
        int startHour = (musicInfo[0]-'0')*10+(musicInfo[1]-'0');
        int startMinute = (musicInfo[3]-'0')*10+(musicInfo[4]-'0');
        int endHour = (musicInfo[6]-'0')*10+(musicInfo[7]-'0');
        int endMinute = (musicInfo[9]-'0')*10+(musicInfo[10]-'0');
        
        int t = (endHour*60+endMinute)-(startHour*60+startMinute);
        
        
        int j;
        string name="";
        for(j=12;musicInfo[j]!=',';j++){
            name = name+musicInfo[j];
        }
        j++;
        string song="";
        for(int k=j;k<musicInfo.size();k++){
            song = song + musicInfo[k];
        }
        string songRep="";
        for(int l=0;l<t;l++){
            songRep = songRep + song[l%song.size()];
        }
        if(songRep.find(m)!=-1){
            if(p.second < t){
                p=make_pair(name,t);
                answer = p.first;
            }
        }
    }
    return answer;
}