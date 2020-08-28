#include <bits/stdc++.h>
using namespace std;

int m[101][101], visit[101];
int n, a, b, cases, tar1, tar2, answer = 101;

void dfs(int index, int cnt) {
    if (index == tar2) {
        answer = min(answer, cnt);
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (visit[i] == 0 && m[index][i] == 1) {
                visit[i] = 1;
                dfs(i, cnt + 1);
                visit[i] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> tar1 >> tar2 >> cases;
    for (int i = 1; i <= cases; i++) {
        cin >> a >> b;
        m[a][b] = 1;
        m[b][a] = 1;
    }

    visit[tar1] = 1;
    dfs(tar1, 0);

    if (answer == 101)  cout << -1;
    else                cout << answer;
}