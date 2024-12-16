#include <bits/stdc++.h>

using namespace std;

int arr[201];
int dp[201];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    int mx = 0;
    for(int i = 0; i < n; ++i){
        dp[i] = 1;
        for(int j = 0; j < i; ++j){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        mx = max(mx, dp[i]);
    }

    cout << n - mx;
}