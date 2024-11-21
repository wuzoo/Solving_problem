#include <bits/stdc++.h>

using namespace std;

long long dp[201][201];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    dp[0][0] = 1;

    for(int i = 0; i <= n; ++i){
        dp[i][1] = 1;
    }

    for(int i = 2; i <= k; ++i){
        for(int j = 0; j <= n; ++j){
            long long sum = 0;

            for(int u = j; u >= 0; --u){
                sum += dp[u][i - 1];
            }

            dp[j][i] = sum % 1000000000;
        }
    }

    for(int i = 0; i <= n; ++i){
        cout << dp[0][i] << ' ';
    }

    cout << '\n' << dp[n][k];
}