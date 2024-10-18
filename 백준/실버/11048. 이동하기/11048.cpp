#include <bits/stdc++.h>

using namespace std;

int n, m;
int graph[1001][1001];
int dp[1001][1001];

int go(int x, int y){
    if(dp[x][y] != -1) return dp[x][y];

    if(x == n && y == m){
        return graph[n][m];
    }

    dp[x][y] = 0;

    int one = 0;
    int two = 0;
    int three = 0;

    if(x + 1 <= n){
        one = go(x + 1, y);
    }
    if(y + 1 <= m){
        two = go(x, y + 1);
    }
    if(x + 1 <= n && y + 1 <= m){
        three = go(x + 1, y + 1);
    }

    dp[x][y] = max(max(one, two), three) + graph[x][y];

    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> graph[i][j];
            dp[i][j] = -1;
        }
    }

    go(1, 1);

    cout << dp[1][1];
}   