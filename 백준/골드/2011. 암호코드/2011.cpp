#include <bits/stdc++.h>
#define MOD 1000000;

using namespace std;

int dp[5001];
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;
    
    if(s[0] == '0'){
        cout << 0;
        return 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= s.length(); ++i){
        if(s[i - 1] != '0') dp[i] = dp[i - 1] % MOD;
        
        int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if(num >= 10 && num <= 26){
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
    }

    cout << dp[s.length()];
}   