#include <bits/stdc++.h>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int sea[302][302], visit[302][302], h, w, answer = 1;
queue< pair<int, int> > ice;

void dfs(int a, int b) {
    visit[b][a] = 1;
    for (int i = 0; i < 4; i++) {
        int aa = a + dx[i];
        int bb = b + dy[i];
        if (aa >= 1 && aa <= w && bb >= 1 && bb <= h && visit[bb][aa] != 1 && sea[bb][aa] != 0) {
            dfs(aa, bb);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> sea[i][j];
            if (sea[i][j] >= 1)  ice.push(make_pair(j, i));
        }
    }

    while (!ice.empty()) {
        int iceNum = ice.size();
        while (iceNum--) {
            int cnt = 0;
            int x = ice.front().first;
            int y = ice.front().second;
            ice.pop();

            visit[y][x] = 1;

            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];

                if (xx >= 1 && xx <= w && yy >= 1 && yy <= h && visit[yy][xx] == 0 && sea[yy][xx] == 0) {
                    cnt++;
                }
            }
            sea[y][x] = max(0, sea[y][x] - cnt);
            if (sea[y][x] > 0) {
                ice.push(make_pair(x, y));
            }
        }

        memset(visit, 0, sizeof(visit));
        int cnt = 0;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (visit[i][j] == 0 && sea[i][j] != 0) {
                    dfs(j, i);
                    cnt++;
                }
            }
        }

        if (cnt == 0) {
            cout << 0;
            exit(0);
        }
        else if (cnt != 1) {
            cout << answer;
            exit(0);
        }

        answer++;
        memset(visit, 0, sizeof(visit));
    }
}