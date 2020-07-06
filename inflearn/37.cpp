#include <iostream>

using namespace std;

int main(){
	int s, n, work;
	scanf("%d", &s);	scanf("%d", &n);
	
	int arr[s] = {0, };
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &work);
		int flag = 0;
		
		for(int j = 0; j < s; j++){
			// cache hit
			if(work == arr[j]){
				flag = 1;
				
				for(int k = j; k > 0; k--)
					arr[k] = arr[k - 1];
				arr[0] = work;
				
				break;
			}
		}
		
		// cache miss
		if(flag == 0){
			for(int j = s; j > 0; j--)
				arr[j] = arr[j - 1];
			arr[0] = work;
		}
	}
	
	for(auto k : arr)
		printf("%d ", k);	
}
