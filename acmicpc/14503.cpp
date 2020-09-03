#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int back_dx[4] = { 1, 0, -1, 0 };
int back_dy[4] = { 0, -1, 0, 1 };
int ans, n, m, r, c, d, arr[51][51];

void dfs(int x, int y, int direction) {
    if (arr[x][y] == 1) return;
    if (arr[x][y] == 0) {
        arr[x][y] = 2;
        ans++;
    }

    for (int k = 0; k < 4; k++) {
        int next_direction = direction - 1 < 0 ? 3 : direction - 1;
        int next_x = x + dx[next_direction];
        int next_y = y + dy[next_direction];

        if (arr[next_x][next_y] == 0) {
            dfs(next_x, next_y, next_direction);
            return;
        }
        else
            direction = next_direction;
    }

    dfs(x + back_dx[direction], y + back_dy[direction], direction);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> r >> c >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    dfs(r, c, d);
    cout << ans;
}