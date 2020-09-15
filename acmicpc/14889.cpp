#include <bits/stdc++.h>
using namespace std;

int n, arr[21][21], answer = 2147000000;
vector<int> v;

int stat(vector<int> team){
    int result = 0;
    int tSize = team.size();
    for(int i = 0; i < tSize; i++){
        for(int j = 0; j < tSize; j++){
            result += arr[team[i]][team[j]];
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= n / 2 ; i++){
        v.push_back(0);
        v.push_back(1);
    }
    sort(v.begin(), v.end());

    do{ 
        vector<int> start;
        vector<int> link;
        for(int i = 0; i < v.size(); i++){
            if(v[i] == 0)   start.push_back(i + 1);
            else            link.push_back(i + 1);
        }

        answer = min(abs(stat(start) - stat(link)), answer);

    }while(next_permutation(v.begin(), v.end()));

    cout << answer;
}