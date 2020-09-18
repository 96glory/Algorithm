#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> rel;
vector<vector<int>> answer;
int col, row, arr[21];

bool vector_is_equal(vector<string> a, vector<string> b){
    int vec_size = a.size();
    for(int i = 0; i < vec_size; i++){
        if(a[i] != b[i])    return false;
    }
    return true;
}

void dfs(int goal, int cnt, int idx){
    if(goal == cnt){
        for(auto i : answer){
            int ans_idx = 0;
            for(int j = 0; j < goal; j++){
                if(i[ans_idx] == arr[j])    ans_idx++;
                if(ans_idx >= i.size())     break;
            }
            if(ans_idx >= i.size()) return;
        }
        
        vector<vector<string>> cmp;
        for(int i = 0; i < row; i++){
            vector<string> tmp;
            for(int j = 0; j < goal; j++)
                tmp.push_back(rel[i][arr[j]]);
            cmp.push_back(tmp);
        }
        
        for(int i = 0; i < row; i++){
            for(int j = i + 1; j < row; j++){
                if(vector_is_equal(cmp[i], cmp[j]))  return;
            }
        }
        
        vector<int> answer_temp;
        for(int i = 0; i < goal; i++)
            answer_temp.push_back(arr[i]);
        answer.push_back(answer_temp);
    }
    else {
        for(int i = idx + 1; i < col; i++){
            arr[cnt] = i;
            dfs(goal, cnt + 1, i);
        }
    }
}

int solution(vector<vector<string>> relation) {
    row = relation.size();
    col = relation[0].size();
    rel = relation;
    
    for(int i = 1; i <= col; i++){
        memset(arr, 0, sizeof(arr));
        dfs(i, 0, -1);
    }
    
    return answer.size();
}