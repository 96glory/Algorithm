#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int n, arr[MAX], dp[MAX], idx[MAX];

void print(int p){
	if (p == -1)    return;
	print(idx[p]);
	cout << arr[p] << ' ';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int max = 1;
	int maxIdx = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		idx[i] = -1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				idx[i] = j;
				dp[i] = dp[j] + 1;
				if (max < dp[i]) {
					max = dp[i];
					maxIdx = i;
				}
			}
		}
	}

	cout << max << endl;
	print(maxIdx);
}