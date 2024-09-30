#include <bits/stdc++.h>

using namespace std;

int graph[501][501];
int dp[501][501];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int DFS(int x, int y);
int n;
int ans = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> graph[i][j];
        }
    }

    int mx = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int count = DFS(i, j);
            ans = max(ans, count);
        }
    }

    cout << ans;
}

int DFS(int x, int y){
    if(dp[x][y]) return dp[x][y];

    dp[x][y] = 1;

    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(graph[nx][ny] <= graph[x][y]) continue;

        dp[x][y] = max(dp[x][y], DFS(nx, ny) + 1);
    }

    return dp[x][y];
}