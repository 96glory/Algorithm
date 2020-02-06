#include <iostream>
#include <cmath>

using namespace std;

int cases, n;
int arr[100001][2], result[100001][2];

int main(){
	cin >> cases;
	for(int i = 0; i < cases; i++){
		cin >> n;
		for(int j = 1; j <= n; j++)
			cin >> arr[j][0];
		for(int j = 1; j <= n; j++)
			cin >> arr[j][1];
		
		result[0][0] = result[0][1] = 0;
		result[1][0] = arr[1][0];
		result[1][1] = arr[1][1];
		
		for(int j = 2; j <= n; j++){
			result[j][0] = max(result[j - 1][1], result[j - 2][1]) + arr[j][0];
			result[j][1] = max(result[j - 1][0], result[j - 2][0]) + arr[j][1];
		}
		
		cout << max(result[n][0], result[n][1]) << endl;
		for(int j = 1; j <= n; j++)
			result[j][0] = result[j][1] = 0;
	}
}
