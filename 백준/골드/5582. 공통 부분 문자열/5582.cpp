#include <bits/stdc++.h>

using namespace std;

int dp[4001][4001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    int ans = 0;

    for(int i = 1; i <= s1.length(); ++i){
        for(int j = 1; j <= s2.length(); ++j){
            if(s2[j - 1] == s1[i - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
}