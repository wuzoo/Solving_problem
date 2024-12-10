#include <bits/stdc++.h>

using namespace std;

int arr[100001][4];
int dp[7];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i){
        cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }

    dp[1] = dp[4] = arr[1][1];
    dp[2] = dp[5] = arr[1][2];
    dp[3] = dp[6] = arr[1][3];

    for(int i = 2; i <= n; ++i){
        int tmp[7];
        for(int j = 1; j <= 6; ++j){
            tmp[j] = dp[j];
        }
        dp[1] = max(tmp[1], tmp[2]) + arr[i][1];
        dp[2] = max(tmp[1], max(tmp[2], tmp[3])) + arr[i][2];
        dp[3] = max(tmp[2], tmp[3]) + arr[i][3];
        dp[4] = min(tmp[4], tmp[5]) + arr[i][1];
        dp[5] = min(tmp[4], min(tmp[5], tmp[6])) + arr[i][2];
        dp[6] = min(tmp[5], tmp[6]) + arr[i][3];
    }

    int mx = 0;
    int mn = 1000001;
    for(int i = 1; i <= 6; ++i){
        mx = max(mx, dp[i]);
        mn = min(mn, dp[i]);
    }

    cout << mx << ' ' << mn;
}