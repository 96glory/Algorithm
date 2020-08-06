#include <iostream>

using namespace std;

int main(){
	int N, input[101], max, answer = 0;
	scanf("%d", &N);
	
	for(int i = 1; i <= N; i++){
		scanf("%d", &input[i]);
	}
	
	max = input[N];
	for(int i = N - 1; i >= 1 ; i--){
		if(input[i] > max){
			answer++;
			max = input[i];
		}
	}
	
	printf("%d", answer);
}

