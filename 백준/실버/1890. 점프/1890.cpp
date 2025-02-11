#include <bits/stdc++.h>

using namespace std;

int n;
int graph[101][101];    
long long dp[101][101];

long long dfs(int x, int y){
    if(dp[x][y]) return dp[x][y];

    if(x == n - 1 && y == n - 1) return 1;
    if(graph[x][y] == 0) return dp[x][y];

    int distance = graph[x][y];

    if(x + distance < n){
        dp[x][y] += dfs(x + distance, y);
    }
    if(y + distance < n){
        dp[x][y] += dfs(x, y + distance);
    }

    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> graph[i][j];
        }
    }

    dfs(0, 0);
    
    cout << dp[0][0];
}