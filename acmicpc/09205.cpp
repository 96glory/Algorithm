#include <bits/stdc++.h>
#define _MAX 102
using namespace std;

int N, cases;
vector<int> graph[_MAX];
bool visited[_MAX];

int distance(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (visited[next] == false)
            dfs(next);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> cases;
    while (cases--) {
        for (int j = 0; j < _MAX; j++) {
            graph[j].clear();
        }
        memset(visited, false, sizeof(visited));

        cin >> N;
        vector<pair<int, int>> coord;
        for (int j = 0; j < N + 2; j++) {
            int y, x;
            cin >> y >> x;
            coord.push_back(make_pair(y, x));
        }

        for (int j = 0; j < N + 2; j++) {
            for (int k = j + 1; k < N + 2; k++) {
                if (distance(coord[j], coord[k]) <= 50 * 20) {
                    graph[j].push_back(k);
                    graph[k].push_back(j);
                }
            }
        }

        dfs(0);

        if (visited[N + 1]) cout << "happy" << endl;
        else                cout << "sad" << endl;
    }
}