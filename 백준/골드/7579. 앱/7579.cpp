#include <bits/stdc++.h>

using namespace std;

int memory[101];
int cost[101];
long long dp[101][10001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        cin >> memory[i];
    }
    for(int i = 1; i <= n; ++i){
        cin >> cost[i];
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= 10001; ++j){
            dp[i][j] = dp[i - 1][j];
            if(j - cost[i] >= 0){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
            }
        }
    }

    cout << lower_bound(dp[n], dp[n] + 10001, m) - dp[n];
}