#include <bits/stdc++.h>
using namespace std;

int N, M, num[2001], a, b, is_palindrome[2001][2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }

    int gap = 0;
    for (int start_idx = 1; start_idx + gap <= N; start_idx++) {
        int end_idx = start_idx + gap;
        is_palindrome[start_idx][end_idx] = 1;
    }

    gap = 1;
    for (int start_idx = 1; start_idx + gap <= N; start_idx++) {
        int end_idx = start_idx + gap;
        if (num[start_idx] == num[end_idx])
            is_palindrome[start_idx][end_idx] = 1;
    }

    for (gap = 2; gap <= N; gap++) {
        for (int start_idx = 1; start_idx + gap <= N; start_idx++) {
            int end_idx = start_idx + gap;
            if (is_palindrome[start_idx + 1][end_idx - 1] && num[start_idx] == num[end_idx])
                is_palindrome[start_idx][end_idx] = 1;
        }
    }

    cin >> M;
    while (M--) {
        cin >> a >> b;
        cout << is_palindrome[a][b] << '\n';
    }
    return 0;
}