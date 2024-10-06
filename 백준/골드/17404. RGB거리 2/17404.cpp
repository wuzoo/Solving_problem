#include <bits/stdc++.h>
#define INF 1000001

using namespace std;

int v[1001][4];
int dp[1001][4];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int ans = INF;

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i){
        int r, g, b;
        cin >> r >> g >> b;

        v[i][1] = r;
        v[i][2] = g;
        v[i][3] = b;
    }

    for(int i = 1; i <= 3; ++i){
        for(int j = 1; j <= 3; ++j){
            if(i == j) continue;
            dp[1][j] = INF;
        }
        dp[1][i] = v[1][i];

        for(int j = 2; j <= n; ++j){
            dp[j][1] = min(dp[j - 1][2], dp[j - 1][3]) + v[j][1];
            dp[j][2] = min(dp[j - 1][1], dp[j - 1][3]) + v[j][2];
            dp[j][3] = min(dp[j - 1][1], dp[j - 1][2]) + v[j][3];
        }

        for(int k = 1; k <= 3; ++k){
            if(i == k) continue;
            ans = min(ans, dp[n][k]);
        }   
    }

    cout << ans;
}