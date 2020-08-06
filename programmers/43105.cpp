#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> t) {
    for(int i = 1; i < t.size(); i++){
        for(int j = 0; j < t[i].size(); j++){
            if(j == 0)                      t[i][j] += t[i - 1][j];
            else if(j == t[i].size() - 1)   t[i][j] += t[i - 1][j - 1];
            else                            t[i][j] += max(t[i - 1][j - 1], t[i - 1][j]);
        }
    }

    int answer = -1;
    for(auto d : t[t.size() - 1]){
        if(d > answer)  answer = d;
    }
    return answer;
}
