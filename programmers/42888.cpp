#include <bits/stdc++.h>
#define ACT 0
#define ID 1
#define NAME 2
using namespace std;

vector<string> answer;
vector<pair<string, string>> logs;
map<string, string> m;

vector<string> solution(vector<string> record) {
    int rSize = record.size();
    int lSize;
    for(int i = 0; i < rSize; i++){
        int k = 0;
        string action[3];
        for(int j = 0; record[i][j] != '\0'; j++){
            if(record[i][j] == ' ') k++;
            else    action[k].push_back(record[i][j]);
        }
        
        if(action[ACT] == "Enter" || action[ACT] == "Leave"){
            logs.push_back(make_pair(action[ID], action[ACT]));
        }
        
        if(action[ACT] == "Enter" || action[ACT] == "Change"){
            m[action[ID]] = action[NAME];
        }
    }
    
    lSize = logs.size();
    for(int i = 0; i < lSize; i++){
        string temp = m[logs[i].first];
        if(logs[i].second == "Enter")
            temp.append("님이 들어왔습니다.");
        else
            temp.append("님이 나갔습니다.");
        answer.push_back(temp);
    }
    
    return answer;
}