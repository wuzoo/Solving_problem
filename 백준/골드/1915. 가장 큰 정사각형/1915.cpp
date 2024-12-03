#include <bits/stdc++.h>

using namespace std;

int n, m;

int graph[1001][1001];
int dp[1001][1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            char c;
            cin >> c;
            graph[i][j] = c - '0';
        }       
    }
    
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(graph[i][j] == 1){
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;

                ans = max(ans, dp[i][j]);
            }
        }
    }
    
    cout << pow(ans, 2);
}