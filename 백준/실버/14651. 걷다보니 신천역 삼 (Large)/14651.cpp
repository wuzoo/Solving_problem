#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[33334][4];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    dp[1][1] = 1;
    dp[1][2] = 1;

    for(int i = 2; i <= n; ++i){
        dp[i][0] = ( dp[i - 1][0] + dp[i - 1][2] + dp[i - 1][1] ) % 1000000009;
        dp[i][1] = ( dp[i - 1][0] + dp[i - 1][2] + dp[i - 1][1] ) % 1000000009;
        dp[i][2] = ( dp[i - 1][0] + dp[i - 1][2] + dp[i - 1][1] ) % 1000000009;
    }

    cout << dp[n][0];
}