#include <bits/stdc++.h>

using namespace std;

int dp[31];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    dp[0] = 1; dp[1] = 0; dp[2] = 3; dp[3] = 0;
    
    for(int i = 4; i <= n; ++i){
        if(i % 2 != 0){
            dp[i] = 0;
            continue;
        }

        int sum = 3 * dp[i - 2];
        int tmp = i - 2;
        int tSum = 0;

        while(tmp >= 0){
            tSum += dp[tmp - 2];
            tmp -= 2;
        }

        dp[i] = sum + 2 * tSum;
    }

    cout << dp[n];
}