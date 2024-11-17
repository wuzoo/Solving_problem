#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int arr[1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    dp[0] = arr[0];
    for(int i = 0; i < n; ++i){
        int cur = arr[i];
        dp[i] = cur;
        for(int j = 0; j < i; ++j){
            if(cur > arr[j]){
                dp[i] = max(dp[i], dp[j] + cur);
            }
        }
    }

    int mx = 0;
    for(int i = 0; i < n; ++i){
        mx = max(mx, dp[i]);
    }

    cout << mx;
}