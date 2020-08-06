#include <iostream>

using namespace std;

int main(){
	int i = 100000000, ii = 9, answer = 0;
	int N;
	
	scanf("%d", &N);
	
	while(-1){
		if(N / i > 0){
			int j = i / 10;
			int jj = ii - 1;
			while(j > 0){
				answer += jj * (j * 10 - 1 - j + 1);
				j /= 10;
				jj--;
			}
			answer += ii * (N - i + 1);
			break;
		}
		i /= 10;
		ii--;
	}
	
	printf("%d", answer);
}
