#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> v;
bool chk[8];
int nums[8];

void dfs(int depth, int index){
    if (depth == M){
        for (int i=0; i<M; ++i) printf("%d ", nums[i]);
        puts("");
        return;
    }
    int before = -1;
    for (int i=index; i<v.size(); ++i){
        if (!chk[i] && (i == 0 || before != v[i])) {
            before = v[i];
            nums[depth] = v[i];
            chk[i] = true;
            dfs(depth + 1, i);
            chk[i] = false;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int val;
    for (int i=0; i<N; ++i) {
        scanf("%d", &val);
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    dfs(0, 1);

    return 0;
}
