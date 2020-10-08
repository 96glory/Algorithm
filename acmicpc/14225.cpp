#include <bits/stdc++.h>
using namespace std;

int n, temp;
vector<int> v;
vector<int> candidate;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    candidate.push_back(v[0]);
    for(int i = 1; i < n; i++){
        int candidate_size = candidate.size();
        for(int j = 0; j < candidate_size; j++){
            candidate.push_back(v[i] + candidate[j]);
        }
        candidate.push_back(v[i]);
        sort(candidate.begin(), candidate.end());
        candidate.erase(unique(candidate.begin(), candidate.end()), candidate.end());
    }

    int can_size = candidate.size(), answer = 1;
    for(int i = 0; i < can_size; i++){
        if(i + 1 != candidate[i]){
            break;
        }
        answer++;
    }

    cout << answer;
}