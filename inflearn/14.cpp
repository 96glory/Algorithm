#include <iostream>
#include <cmath>

using namespace std;

int reverse(int x){
	int output = 0;
	while(x > 0){
		output *= 10;
		output += x % 10;
		x /= 10;
	}
	
	return output;
}

bool isPrime(int x){
	if(x == 1)		return false;
	else if(x == 2)	return true;
	
	for(int i = 2; i <= sqrt(x); i++){
		if(x % i == 0)	return false;
	}
	
	return true;
}

int main(){
	int N, temp;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++){
		scanf("%d", &temp);
		int reverseTemp = reverse(temp);
		if(isPrime(reverseTemp))
			printf("%d ", reverseTemp);
	}
}

