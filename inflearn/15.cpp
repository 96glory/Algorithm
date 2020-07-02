#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int N;	scanf("%d", &N);
	int answer = 0;
	
	for(int i = 2; i <= N; i++){
		int flag = 1;
		for(int j = 2; j * j <= i; j++){
			if(i % j == 0){
				flag = 0;
				break;
			}
		}
		if(flag == 1)	answer++;
	}
	
	printf("%d", answer);
}

