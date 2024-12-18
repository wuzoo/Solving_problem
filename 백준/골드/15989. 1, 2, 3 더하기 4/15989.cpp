#include <bits/stdc++.h>

using namespace std;

int dp[10001][4];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        dp[0][1] = 1;
        dp[1][1] = 1;
        for(int i = 2; i <= n; ++i){ 
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 2][2] + dp[i - 2][1];

            if(i >= 3){
                dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
            }
        }

        cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';

        memset(dp, 0, sizeof(dp));
    }
}