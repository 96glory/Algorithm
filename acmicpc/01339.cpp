#include <bits/stdc++.h>
using namespace std;

struct Le{
	char letter;
	int value;
	Le(char a, int b){
		letter = a;
		value = b;
	}
	bool operator < (const Le & b) const {
		return value > b.value;
	}
};

int n, answer;
string temp;
map<char, int> m;
vector<Le> exist;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> temp;
		for(int i = 0; i < temp.length(); i++){
			m[temp[i]] += pow(10, temp.length() - i - 1);
		}
	}
	
	for(auto & i : m){
		if(i.second != 0){
			exist.push_back(Le(i.first, i.second));
		}
	}
	
	int cnt = 9;
	sort(exist.begin(), exist.end());
	for(auto i : exist){
		answer += (cnt * i.value);
		cnt--;
	}

	cout << answer;
}

