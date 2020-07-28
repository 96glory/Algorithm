#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> temp;
    vector<int> answer;

    for(int i = 0; i < commands.size(); i++){
        temp = array;
        sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);
        answer.push_back(temp[(commands[i][0] - 1) + (commands[i][2] - 1)]);
    }

    return answer;
}
