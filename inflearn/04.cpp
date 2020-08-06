#include <iostream>

using namespace std;

int main(){
	int N, min = 987654321, max = -987654321;
	int arr[100];
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		if(arr[i] < min){
			min = arr[i];
		}
		if(arr[i] > max){
			max = arr[i];
		}
	}
	cout << max - min;
}

