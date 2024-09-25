#include <bits/stdc++.h>

using namespace std;

int dp[1001][11];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i <= 9; ++i){
        dp[1][i] = 1;
    }
    for(int i = 2; i <= n; ++i){
        for(int j = 0; j <= 9; ++j){   
            int sum = 0;
            for(int k = j; k >= 0; --k){
                sum += dp[i - 1][k];
            }  
            dp[i][j] = sum % 10007;
        }
    }

    int sum = 0;
    for(int i = 0; i <= 9; ++i){
        sum += dp[n][i];
    }
    cout << sum % 10007;
}