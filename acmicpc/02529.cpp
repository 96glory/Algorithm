#include <bits/stdc++.h>
using namespace std;

int n;
char tmp;
vector<char> op;
string temp, max_answer, min_answer;

void dfs(int level, int visit) {
    if(level == n + 1) {
        do {
            bool flag = true;
            for(int i = 0; i < n; i++){
                if(op[i] == '<'){
                    if(temp[i] < temp[i + 1])   continue;
                    else{
                        flag = false;
                        break;
                    }
                }
                else{
                    if(temp[i] > temp[i + 1])   continue;
                    else{
                        flag = false;
                        break;
                    }
                }
            }

            if(flag){
                if(max_answer < temp)    max_answer = temp;
                if(min_answer > temp)    min_answer = temp;
            }
        }while(next_permutation(temp.begin(), temp.end()));

        sort(temp.begin(), temp.end());
    }
    else {
        for(int i = visit + 1; i <= 9; i++){
            temp[level] = i + '0';
            dfs(level + 1, i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    for(int i = 0; i <= n; i++){
        if(i != n){
            cin >> tmp;
            op.push_back(tmp);
        }

        max_answer.push_back('0');
        min_answer.push_back('9');
        temp.push_back('0');
    }

    dfs(0, -1);

    cout << max_answer << endl << min_answer;
}