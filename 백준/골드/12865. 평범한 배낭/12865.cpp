#include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[101][100001];
int w[101];
int v[101];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;

    for(int i = 1; i <= n; ++i){
        int a, b;
        cin >> a >> b;
        w[i] = a;
        v[i] = b;
    }
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            dp[i][j] = dp[i - 1][j];
            if(j - w[i] >= 0){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[n][k];
}