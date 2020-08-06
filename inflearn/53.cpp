#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int main(){
	int n, k, temp;
	scanf("%d %d", &n, &k);
	
	while(n > 0){
		s.push(n % k);
		n /= k;
	}
	while(!s.empty()){
		temp = s.top();
		s.pop();
		if(k == 16 && temp >= 10){
			if(temp == 10)	printf("A");
			if(temp == 11)	printf("B");
			if(temp == 12)	printf("C");
			if(temp == 13)	printf("D");
			if(temp == 14)	printf("E");
			if(temp == 15)	printf("F");
		}
		else	printf("%d", temp);
	}
}
