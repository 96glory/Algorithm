#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> s;
vector<char> v;

int main(){	
	int i, n, find = 1, temp;
	scanf("%d", &n);
	
	vector<char> str;
	
	for(i = 1; i <= n; i++){
		scanf("%d", &temp);
		s.push(temp);
		str.push_back('P');
		while(-1){
			if(s.empty())	break;
			if(find == s.top()){
				s.pop();
				find++;
				str.push_back('O');
			}
			else	break;
		}
	}
	
	if(!s.empty())	printf("impossible");
	else{
		for(auto k: str)	printf("%c", k);
	}
}
