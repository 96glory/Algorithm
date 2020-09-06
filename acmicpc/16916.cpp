#include <bits/stdc++.h>
using namespace std;

char a[1000001], b[1000001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	
	cin >> a >> b;
	if (strstr(a, b) == NULL)	cout << 0;
	else						cout << 1;
}