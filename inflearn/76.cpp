#include <iostream>

using namespace std;

// n C r = n-1 C r-1 + n-1 C r
int n, r, arr[21][21];

int dp(int _n, int _r){
	if(_r == 0 || _n == _r) return 1;
	if(arr[_n][_r] != 0) return arr[_n][_r];
	return arr[_n][_r] = dp(_n - 1, _r - 1) + dp(_n - 1, _r);
}

int main(){
	scanf("%d %d", &n, &r);
	printf("%d", dp(n, r));
}

