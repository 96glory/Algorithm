#include <bits/stdc++.h>
using namespace std;

int n, start, target, up, down, answer, flag;
bool visit[1000001];
queue< pair<int, int> > q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> start >> target >> up >> down;

    q.push(make_pair(start, 0));
    while (!q.empty()) {
        int where = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (visit[where])    continue;
        visit[where] = true;

        if (where == target) {
            answer = cnt;
            flag = 1;
            break;
        }

        if (up != 0 && where + up <= n)
            q.push(make_pair(where + up, cnt + 1));
        if (down != 0 && where - down >= 1)
            q.push(make_pair(where - down, cnt + 1));
    }

    if (flag == 0)
        cout << "use the stairs";
    else
        cout << answer;
}