#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

const int n_ = 2000 + 1;

bool ans, chk[n_];
int n, m;
vector<int> v[n_];

void dfs(int now, int cnt) {
	if (cnt == 5) {
		ans = true;
		return;
	}

	chk[now] = true;
	for (int next : v[now]) {
		if (!chk[next]) dfs(next, cnt + 1);
		if (ans) return;
	}
	chk[now] = false;
}

int main() {
	int i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (i = 0; i < n; ++i) {
		memset(chk, false, sizeof(chk));
		dfs(i, 1);
		if (ans) break;
	}

	if (ans) puts("1");
	else puts("0");

	return 0;
}
