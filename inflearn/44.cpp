#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int count(int len, int x[]){
	int i, cnt = 1, pos = x[1];
	for(i = 2; i <= n; i++){
		if(x[i] - pos >= len){
			cnt++;
			pos = x[i];
		}
	}
	return cnt;
}

int main(){
	int m, i, left = 1, right, mid, answer;
	scanf("%d", &n);	scanf("%d", &m);
	
	int * x = new int[n + 1];
	for(i = 1; i <= n; i++)	scanf("%d", &x[i]);
	
	sort(x + 1, x + n + 1);
	right = x[n];
	while(left <= right){
		mid = (left + right) / 2;
		if(count(mid, x) >= m){
			answer = mid;
			left = mid + 1;
		}
		else	right = mid - 1;
	}
	printf("%d", answer);
	delete[] x;
}
