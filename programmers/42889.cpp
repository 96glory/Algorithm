#include <bits/stdc++.h>
using namespace std;

struct Stage{
    int idx;
    int s;
    int f;
    float rate;
    Stage(int i, int a, int b){
        idx = i; s = a; f = b; rate = 0;
    }
    void setS(){
        s++;
    }
    void setF(){
        f++;
    }
    void calcRate(){
        if(s + f == 0){
            rate = 0;
        }
        else{
            rate = (float) f / (float) (s + f);    
        }
    }
    bool operator < (const Stage & b) const {
        if(rate == b.rate){
            return idx < b.idx;
        }
        return rate > b.rate;
    }
};

vector<int> answer;
vector<Stage> v;

vector<int> solution(int N, vector<int> stages) {
    for(int i = 1; i <= N; i++)
        v.push_back(Stage(i, 0, 0));
    
    for(int i = 0; i < stages.size(); i++){
        if(stages[i] > N){
            for(int j = 0; j <= N - 1; j++)
                v[j].setS();
        }
        else {
            for(int j = 0; j <= stages[i] - 2; j++)
                v[j].setS();
            v[stages[i] - 1].setF();
        }
    }
    
    for(int i = 0; i < N; i++)  v[i].calcRate();
    sort(v.begin(), v.end());
    
    for(int i = 0; i < N; i++)  answer.push_back(v[i].idx);
    return answer;
}