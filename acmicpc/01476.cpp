#include <iostream>

using namespace std;

int year = 1;

int main(){
	int E, S, M;
	int e = 1, s = 1, m = 1;
	cin >> E >> S >> M;
	
	while(-1){
		if(e == E && s == S && m == M){
			break;
		}
		
		year++;
		
		e++;
		s++;
		m++;
		if(e == 16)	e = 1;
		if(s == 29)	s = 1;
		if(m == 20)	m = 1;
	}
	
	cout << year;
	
}
