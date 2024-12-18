#include <bits/stdc++.h>

using namespace std;

long long dp[10000001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    
    while(t--){
        int n; cin >> n;

        dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 4;
        for(int i = 4; i <= n; ++i){
            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
        }

        cout << dp[n] << '\n';
    }
}