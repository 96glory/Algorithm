#include <iostream>

using namespace std;

int main(){
	int N, sum = 0;
	scanf("%d", &N);
	
	// 1~9 10~99 100~999 1000~9999 10000~99999
	
	if(N / 10000 > 0){
		sum = 9 + 2 * (99 - 10 + 1) + 3 * (999 - 100 + 1) + 4 * (9999 - 1000 + 1) + 5 * (N - 10000 + 1);
	}
	else if(N / 1000 > 0){
		sum = 9 + 2 * (99 - 10 + 1) + 3 * (999 - 100 + 1) + 4 * (N - 1000 + 1);
	}
	else if(N / 100 > 0){
		sum = 9 + 2 * (99 - 10 + 1) + 3 * (N - 100 + 1);
	}
	else if(N / 10 > 0){
		sum = 9 + 2 * (N - 9);
	}
	else{
		sum = N;
	}
	printf("%d", sum);
}
