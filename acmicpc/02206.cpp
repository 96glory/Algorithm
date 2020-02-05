#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M;
int arr[1000][1000];
bool v[1000][1000][2];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int BFS(){
    queue<pair<pair<int, int>, pair<int,int>>> Q;
    Q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
    v[0][0][0] = true;
 
    while (!Q.empty()){
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int B = Q.front().second.first;
        int cnt = Q.front().second.second;
        Q.pop();
 
        if (x == N - 1 && y == M - 1)	return cnt;
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < N && ny < M){
                if (arr[nx][ny] == 1 && B == 0){
                    v[nx][ny][B+1] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(B + 1, cnt + 1)));
                }
                else if (arr[nx][ny] == 0 && v[nx][ny][B] == false){
                    v[nx][ny][B] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(B, cnt + 1)));
                }
            }
        }
    }
    return -1;
}

int main(){
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		string temp;
		cin >> temp;
		for(int j = 0; j < M; j++)
			arr[i][j] = temp[j] - '0';
	}
	cout << BFS();
}

