#include <bits/stdc++.h>
using namespace std;

int n, _max, answer = -1;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
vector<vector<int>> arr, visit;

void dfs(int a, int b, int flood) {
    visit[a][b] = 1;
    for (int i = 0; i < 4; i++) {
        int aa = a + dx[i];
        int bb = b + dy[i];
        if (aa >= 1 && aa <= n && bb >= 1 && bb <= n && visit[aa][bb] != 1 && arr[aa][bb] > flood) {
            dfs(aa, bb, flood);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    arr.assign(n + 1, vector<int>(n + 1, 0));
    visit.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            _max = max(arr[i][j], _max);
        }
    }

    for (int flood = 0; flood <= _max; flood++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            fill(visit[i].begin(), visit[i].end(), 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] > flood && visit[i][j] != 1) {
                    dfs(i, j, flood);
                    cnt++;
                }
            }
        }
        answer = max(answer, cnt);
    }

    cout << answer;
}