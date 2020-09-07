#include <bits/stdc++.h>
using namespace std;

const int RIGHT = 0;
const int LEFT = 1;
const int UP = 2;
const int DOWN = 3;
int n, answer = -1;

vector<vector<int>> solve(vector<vector<int>> v, int dir){
    if(dir == RIGHT){
        for(int i = 1; i <= n; i++){
            for(int j = n; j >= 1; j--){
                for(int k = j - 1; k >= 1; k--){
                    if(v[i][k] == 0) continue;
                    else {
                        if(v[i][k] == v[i][j]){
                            v[i][j] *= 2;
                            v[i][k] = 0;
                        }
                        else {
                            if(v[i][j] == 0){
                                v[i][j] = v[i][k];
                                v[i][k] = 0;
                                j++;
                            }   
                            else{
                                if(j - 1 != k){
                                    v[i][j - 1] = v[i][k];
                                    v[i][k] = 0;
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    if(dir == LEFT){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                for(int k = j + 1; k <= n; k++){
                    if(v[i][k] == 0) continue;
                    else {
                        if(v[i][k] == v[i][j]){
                            v[i][j] *= 2;
                            v[i][k] = 0;
                        }
                        else {
                            if(v[i][j] == 0){
                                v[i][j] = v[i][k];
                                v[i][k] = 0;
                                j--;
                            }   
                            else{
                                if(j + 1 != k){
                                    v[i][j + 1] = v[i][k];
                                    v[i][k] = 0;
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    if(dir == UP){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                for(int k = j + 1; k <= n; k++){
                    if(v[k][i] == 0) continue;
                    else {
                        if(v[k][i] == v[j][i]){
                            v[j][i] *= 2;
                            v[k][i] = 0;
                        }
                        else {
                            if(v[j][i] == 0){
                                v[j][i] = v[k][i];
                                v[k][i] = 0;
                                j--;
                            }   
                            else{
                                if(j + 1 != k){
                                    v[j + 1][i] = v[k][i];
                                    v[k][i] = 0;
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }

    }
    if(dir == DOWN){
        for(int i = 1; i <= n; i++){
            for(int j = n; j >= 1; j--){
                for(int k = j - 1; k >= 1; k--){
                    if(v[k][i] == 0) continue;
                    else {
                        if(v[k][i] == v[j][i]){
                            v[j][i] *= 2;
                            v[k][i] = 0;
                        }
                        else {
                            if(v[j][i] == 0){
                                v[j][i] = v[k][i];
                                v[k][i] = 0;
                                j++;
                            }   
                            else{
                                if(j - 1 != k){
                                    v[j - 1][i] = v[k][i];
                                    v[k][i] = 0;
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
    }

    return v;
}

void dfs(vector<vector<int>> v, int depth){
    if(depth == 5){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                answer = max(answer, v[i][j]);
        return;
    }
    else {
        for(int i = 0; i < 4; i++)
            dfs(solve(v, i), depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    vector< vector<int> > MAP(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> MAP[i][j];

    dfs(MAP, 0);
    cout << answer;
}