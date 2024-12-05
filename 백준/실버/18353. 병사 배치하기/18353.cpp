#include <bits/stdc++.h>

using namespace std;

int arr[2001];
int dp[2001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];       
    }

    for(int i = 0; i < n; ++i){
        dp[i] = 1;
        for(int j = 0; j < i; ++j){
            if(arr[i] < arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int mx = 0;
    for(int i = 0; i < n; ++i){
        mx = max(mx, dp[i]);
    }

    cout << n - mx;
}