#include <bits/stdc++.h>
using namespace std;

int n, cnt, ans;
char candy[51][51];

void check(){
	for (int i = 1; i <= n; i++){
		cnt = 1;
		for (int j = 2; j <= n; j++){
			if (candy[i][j - 1] == candy[i][j]){
				cnt++;
			}
			else{
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);
	}

	for (int i = 1; i <= n; i++){
		cnt = 1;
		for (int j = 2; j <= n; j++){
			if (candy[j-1][i] == candy[j][i]){
				cnt++;
			}
			else{
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> candy[i][j];
		}
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if ((j + 1) <= n){
				swap(candy[i][j], candy[i][j + 1]);
				check();
				swap(candy[i][j], candy[i][j + 1]);
			}
			if ((i + 1) <= n){
				swap(candy[i][j], candy[i + 1][j]);
				check();
				swap(candy[i][j], candy[i + 1][j]);
			}
		}
	}
	cout << ans;
}