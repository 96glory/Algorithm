#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
priority_queue<int> pq;
int answer[10001];
int n, m, d, sum;

bool compare(pair<int, int> a, pair<int, int> b){
	if(a.second == b.second)
		return a.first > b.first;
	return a.second > b.second;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &m, &d);
		v.push_back(make_pair(m, d));
	}
	sort(v.begin(), v.end(), compare);
	
	int j = 0;
	for(int i = v[0].second; i >= 1; i--){
		for( ; j < n; j++){
			if(v[j].second >= i) pq.push(v[j].first);
			else break;
		}
		if(!pq.empty()){
			sum += pq.top();
			pq.pop();
		}
	}
	printf("%d", sum);
}

