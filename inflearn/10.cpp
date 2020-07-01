#include <iostream>

using namespace std;

int digit_sum(int x){
	int sum = 0;
	while(x > 0){
		sum = sum + (x % 10);
		x /= 10;
	}
	return sum;
}

int main(){
	int temp, temp_sum, max_sum = -987654321, max = -1;
	
	int N;	scanf("%d", &N);
	
	for(int i = 0; i < N; i++){
		scanf("%d", &temp);
		temp_sum = digit_sum(temp);
		if(temp_sum > max_sum){
			max_sum = temp_sum;
			max = temp;
		}
		else if(temp_sum == max_sum && temp > max){
			max = temp;
		}
	}
	printf("%d", max);
}

