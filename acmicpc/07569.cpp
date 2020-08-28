#include <bits/stdc++.h>
using namespace std;

struct tomato {
    int x;
    int y;
    int z;
    tomato(int a, int b, int c) {
        x = a;  y = b;  z = c;
    }
};

int dx[] = { 0, 1, 0, 0, -1, 0 };
int dy[] = { 0, 0, 1, 0, 0, -1 };
int dz[] = { 1, 0, 0, -1, 0, 0 };

int m[101][101][101], _x, _y, _z, emptyCnt, rareCnt, answer = -2147000000;
queue< pair<tomato, int> > q;

bool isRare(int xx, int yy, int zz) {
    return xx >= 1 && xx <= _y && yy >= 1 && yy <= _x && zz >= 1 && zz <= _z && m[xx][yy][zz] == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> _x >> _y >> _z;

    for (int k = 1; k <= _z; k++) {
        for (int i = 1; i <= _y; i++) {
            for (int j = 1; j <= _x; j++) {
                cin >> m[i][j][k];
                if (m[i][j][k] == 1)        q.push(make_pair(tomato(i, j, k), 0));
                else if (m[i][j][k] == -1)  emptyCnt++;
                else if (m[i][j][k] == 0)   rareCnt++;
            }
        }
    }

    if (q.size() + emptyCnt == _x * _y * _z) {
        cout << 0;
        exit(0);
    }

    while (!q.empty()) {
        int x = q.front().first.x;
        int y = q.front().first.y;
        int z = q.front().first.z;
        int day = q.front().second;
        q.pop();

        answer = max(answer, day);

        for (int i = 0; i < 6; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            int zz = z + dz[i];

            if (isRare(xx, yy, zz)) {
                rareCnt--;
                m[xx][yy][zz] = 1;
                q.push(make_pair(tomato(xx, yy, zz), day + 1));
            }
        }
    }

    if (rareCnt == 0)   cout << answer;
    else                cout << -1;
}