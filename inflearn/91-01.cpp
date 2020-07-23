#include <bits/stdc++.h>
using namespace std;

int n, answer[46];

int main(){
	scanf("%d", &n);
	
	answer[1] = 1;
	answer[2] = 2;
	for(int i = 3; i <= n; i++)
		answer[i] = answer[i - 1] + answer[i - 2];
	printf("%d", answer[n]);
}
