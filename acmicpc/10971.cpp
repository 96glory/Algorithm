#include <bits/stdc++.h>
using namespace std;

int n, arr[11][11], visit[11], answer = 2147000000;


void dfs(int start, int i, int sum, int cnt) {
    if (start == i && cnt == n) {
        answer = min(answer, sum);
        return;
    }
    else {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 0)  continue;

            if (!visit[i] && arr[i][j] > 0) {
                visit[i] = true;
                sum += arr[i][j];

                if (sum <= answer)
                    dfs(start, j, sum, cnt + 1);

                visit[i] = false;
                sum -= arr[i][j];
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, i, 0, 0);
    }

    cout << answer;
}