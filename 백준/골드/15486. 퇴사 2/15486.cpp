#include <bits/stdc++.h>

using namespace std;

int duration[1500001];
int cost[1500001];
int dp[1500001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i){
        int t, p;
        cin >> t >> p;

        duration[i] = t;
        cost[i] = p;
    }

    int ans = 0;
    for(int i = 1; i <= n + 1; ++i){
        ans = max(ans, dp[i]);
        dp[i + duration[i]] = max(dp[i + duration[i]], dp[i] + cost[i]);
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }
    
    cout << ans;
}