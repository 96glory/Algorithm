#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b){
	if(a.first.length() == b.first.length()){
		if(a.second == b.second){
			return a.first < b.first;
		}
		else{
			return a.second < b.second;
		}
	}
	else {
		return a.first.length() < b.first.length();
	}
}

int main(){
	int N;
	cin >> N;
	vector<pair<string, int>> v;
	
	string temp;
	for(int i = 0; i < N; i++){
		cin >> temp;
		int sum = 0;
		int len = temp.length();
		const char * ctemp = temp.c_str();
		
		for(int i = 0; i < len; i++){
			if(isdigit(ctemp[i]) != 0)
				sum += ctemp[i] - '0';
		}
		v.push_back(make_pair(temp, sum));
	}
	
	sort(v.begin(), v.end(), compare);
	for(auto k : v)
		cout << k.first << endl;
}
