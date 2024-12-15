#include <bits/stdc++.h>
#define INF 100000001

using namespace std;

int arr[100001];
int dp[100001];
int dprv[100002];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;

    for(int i = 1; i <= n; ++i) cin >> arr[i];

    for(int i = 1; i <= n; ++i){
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    }

    if(n == 1){
        cout << arr[1];
        return 0;
    }

    for(int i = n; i >= 1; --i){
        dprv[i] = max(dprv[i + 1] + arr[i], arr[i]);
    }

    int mx = -INF;
    for(int i = 1; i <= n; ++i){
        mx = max(dp[i - 1] + dprv[i + 1], mx);
    }

    for(int i = 1; i <= n; ++i){
        mx = max(mx, dp[i]);
    }

    cout << mx;
}