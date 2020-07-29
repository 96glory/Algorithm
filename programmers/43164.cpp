#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> t;
vector<int> used;
vector<string> answer;

bool cmp(vector<string> a, vector<string> b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

void dfs(vector<string> path){
    if(!answer.empty()) return;
    
    string temp = path[path.size() - 1];
    if(path.size() == t.size() + 1){
        if(answer.empty()){
            answer = path;
        }
    }
    else{
        for(int i = 0; i < t.size(); i++){
            if(used[i] == 0 && temp == t[i][0]){
                used[i] = 1;
                path.push_back(t[i][1]);
                dfs(path);
                used[i] = 0;
                path.pop_back();
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    t = tickets;
    used.assign(t.size(), 0);
    sort(t.begin(), t.end(), cmp);
    dfs({"ICN"});
    return answer;
}
