#include <iostream>

using namespace std;

int main(){
	int n, temp, answer = 0;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		temp = i;
		while(temp != 0){
			if(temp % 10 == 3){
				answer++;
			}
			temp /= 10;
		}
	}
	
	printf("%d", answer);
}

