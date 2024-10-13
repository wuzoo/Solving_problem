#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, m;
int arr[501][501];
int dp[501][501];

int dfs(int x, int y){
    if(dp[x][y] != -1) return dp[x][y];
    if(x == n - 1 && y == m - 1) return 1;

    dp[x][y] = 0;

    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(arr[nx][ny] >= arr[x][y]) continue;

        dp[x][y] += dfs(nx, ny);
    }

    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> arr[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    dfs(0, 0);

    cout << dp[0][0];
}