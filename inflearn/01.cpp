#include <iostream>

using namespace std;

int main(void){
	int N, M, sum;
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++){
		if(i % M == 0){
			sum += i;
		}
	}
	
	cout << sum;
}
