#include <iostream>

using namespace std;

int answer[1001];

int main(){
	int n;
	scanf("%d", &n);
	
	for(int i = 2; i <= n; i++){
		int temp = i;
		for(int j = 2; j <= i; j++){
			while(temp % j == 0){
				temp /= j;
				answer[j]++;
			}
			if(temp == 1)	break;
		}
	}
	
	printf("%d", min(answer[2], answer[5]));
}
