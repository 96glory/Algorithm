#include <bits/stdc++.h>
using namespace std;

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

struct Loc{
    int x;
    int y;
    Loc(int a, int b) : x(a), y(b) {};
};

char c;
int n, k, l, x, y, idx, t = 1, dir;
vector<pair<Loc, bool>> apple;
vector<pair<int, char>> Rotate;
queue<pair<Loc, int>> snake;

int TURN(int dir, char to){
    if(to == 'L')       return (dir - 1 == -1) ? 3 : dir - 1;
    else if(to == 'D')  return (dir + 1 == 4) ? 0 : dir + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        cin >> x >> y;
        apple.push_back(make_pair(Loc(y, x), false));
    }

    cin >> l;
    for(int i = 1; i <= l; i++){
        cin >> x >> c;
        Rotate.push_back(make_pair(x, c));
    }

    snake.push(make_pair(Loc(1, 1), RIGHT));
    while(-1){
        x = snake.front().first.x;
        y = snake.front().first.y;
        dir = snake.front().second;
        snake.pop();

        int xx = x + dx[dir];
        int yy = y + dy[dir];
        int ddir = dir;
        if(idx < l && Rotate[idx].first == t){
            ddir = TURN(dir, Rotate[idx].second);
            idx++;
        }

        if(!(xx >= 1 && xx <= n && yy >= 1 && yy <= n)) break;
        int tmp = snake.size();
        for(int i = 1; i <= tmp; i++){
            int tx = snake.front().first.x;
            int ty = snake.front().first.y;
            int tdir = snake.front().second;
            snake.pop();

            if(tx == xx && ty == yy){
                cout << t;
                exit(0);
            }

            snake.push(make_pair(Loc(tx, ty), tdir));
        }

        bool gotApple = false;
        for(int i = 0; i < k; i++){
            if(!apple[i].second && apple[i].first.x == xx &&  apple[i].first.y == yy){
                snake.push(make_pair(Loc(x, y), dir));
                int temp = snake.size();
                snake.push(make_pair(Loc(xx, yy), ddir));
                if(temp != 0){
                    for(int i = 1; i <= temp; i++){
                        int tx = snake.front().first.x;
                        int ty = snake.front().first.y;
                        int tdir = snake.front().second;
                        snake.pop();

                        snake.push(make_pair(Loc(tx, ty), tdir));
                    }
                }
                apple[i].second = true;
                gotApple = true;
                break;
            }
        }
        if(!gotApple){
            snake.push(make_pair(Loc(x, y), dir));
            int temp = snake.size();
            snake.push(make_pair(Loc(xx, yy), ddir));
            for(int i = 1; i <= temp; i++){
                int tx = snake.front().first.x;
                int ty = snake.front().first.y;
                int tdir = snake.front().second;
                snake.pop();

                if(i != 1)
                    snake.push(make_pair(Loc(tx, ty), tdir));
            }
        }
        t++;
    }

    cout << t;
}