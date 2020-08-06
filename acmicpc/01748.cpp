#include <bits/stdc++.h>
using namespace std;

int n, answer, cnt;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	
	answer = n;
	while(answer != 0){
		answer /= 10;
		cnt++;
	}
	
	for(int i = 1; i <= cnt; i++){
		if(i == cnt)	answer += (n - pow(10, i - 1) + 1) * i;
		else			answer += (pow(10, i) - pow(10, i - 1)) * i;
	}
	
	cout << answer;
}

