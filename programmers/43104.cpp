#include <bits/stdc++.h>
using namespace std;

long long tiles[81];

long long dp(int N){
    if(N == 1 || N == 2)    return tiles[N] = 1;
    else if(tiles[N] == 0)  return tiles[N] = dp(N - 1) + dp(N - 2);
    else                    return tiles[N];
}

long long solution(int N) {
    return 4 * dp(N) + 2 * dp(N - 1);
}
