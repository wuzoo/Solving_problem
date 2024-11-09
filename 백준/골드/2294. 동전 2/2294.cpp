#include <bits/stdc++.h>

using namespace std;

int dp[10001];
int arr[101];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    for(int i = 1; i <= k; ++i){
        dp[i] = 100000001;
    }

    sort(arr, arr + n);

    for(int i = 1; i <= n; ++i){
        for(int j = arr[i]; j <= k; ++j){
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
        }
    }

    if(dp[k] == 100000001) cout << -1;
    else cout << dp[k];
}