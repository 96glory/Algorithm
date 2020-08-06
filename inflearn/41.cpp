#include <iostream>

using namespace std;

int main(){
	int n, answer = 0, length = 2, sum = 0, i;
	scanf("%d", &n);
	
	for(i = 1; i <= n - length + 1; i++){
		for(int j = i; j < i + length; j++)	sum += j;
		if(sum == n){
			printf("%d ", i);
			for(int j = i + 1; j < i + length; j++)	printf("+ %d ", j);
			printf("= %d\n", n);
			answer++;
			length++;
			i = 0;
		}
		else if(i == 1 && sum > n){
			printf("%d", answer);
			return 0;
		}
		else if(sum > n){
			length++;
			i = 0;
		}
		sum = 0;
	}
}

