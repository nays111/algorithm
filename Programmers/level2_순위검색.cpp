#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int get_language(string str){
    if(str=="java"){return 0;}
    if(str=="cpp"){return 1;}
    if(str=="python"){return 2;}
    return 3;
}

int get_career(string str){
    if(str=="junior"){return 0;}
    if(str=="senior"){return 1;}
    return 2;
}

int get_job(string str){
    if(str=="backend"){return 0;}
    if(str=="frontend"){return 1;}
    return 2;
}

int get_food(string str){
    if(str=="chicken"){return 0;}
    if(str=="pizza"){return 1;}
    return 2;
}

int get_count(int ls,int ll,int js,int jl,int cs,int cl,int fs,int fl,int score, vector<int> v[3][2][2][2]){
    int answer = 0;
    for(int i=ls ; i <= ll ; i++){
        for(int j=js ; j <= jl ; j++){
            for(int k=cs ; k <= cl ; k++){
                for(int l=fs ; l <= fl ; l++){
                    for(int h = 0;h<v[i][j][k][l].size();h++){
                        if(v[i][j][k][l][h] >= score){
                            answer++;
                        }
                    }
                }
            }
        }
    }
    return answer;
}



vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    vector<int> v[3][2][2][2];
    for(int i=0;i<info.size();i++){
        
        string str = info[i];
        string temp = "";
        int index = 0;
        int lang_no, job_no, career_no, food_no;
        for(int j=0;j<str.size();j++){
            if(str[j] == ' '){
                if(index == 0){
                    lang_no = get_language(temp);
                }else if(index == 1){
                    job_no = get_job(temp);
                }else if(index ==2){
                    career_no = get_career(temp);
                }else if(index == 3){
                    food_no = get_food(temp);
                }
                index++;
                temp="";
            }else{
                temp+=str[j];
            }
        }
        
        v[lang_no][job_no][career_no][food_no].push_back(stoi(temp));
    }
    
    for(int i=0;i<query.size();i++){
        string str = query[i];
        string temp = "";
        int index = 0;
        int lang_no, job_no, career_no, food_no;
        int j;
        for(j=0;j<str.size();j++){
            if(str[j] == ' '){
                if(index == 0){
                    lang_no = get_language(temp);
                    j+=4;
                }else if(index == 1){
                    job_no = get_job(temp);
                    j+=4;
                }else if(index ==2){
                    career_no = get_career(temp);
                    j+=4;
                }else if(index == 3){
                    food_no = get_food(temp);
                }
                index++;
                temp="";
            }else{
                temp+=str[j];
            }
        }
        
        int ls,ll;
        if(lang_no == 3){
            ls = 0;
            ll = 2;
        }else{
            ls = ll = lang_no;
        }
        
        int js,jl;
        if(job_no == 2){
            js = 0;
            jl = 1;
        }else{
            js = jl = job_no;
        }
        
        int cs,cl;
        if(career_no == 2){
            cs = 0;
            cl = 1;
        }else{
            cs = cl = career_no;
        }
        
        int fs,fl;
        if(food_no == 2){
            fs = 0;
            fl = 1;
        }else{
            fs = fl = food_no;
        }
        int score = stoi(temp);
        int cnt = get_count(ls,ll,js,jl, cs, cl, fs, fl, score,  v);
        answer.push_back(cnt);
    }
    
    
    
    return answer;
}