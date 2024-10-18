#include <bits/stdc++.h>

using namespace std;

int n;
string s;
string arr[101];
int dp[101];

int go(int len){
    if(len == s.length()) return true;

    if(dp[len] != -1) return dp[len];

    dp[len] = 0;

    for(int i = 0; i < n; ++i){
        int word_len = arr[i].length();

        if(len + word_len > s.size()) continue;

        if(s.substr(len, word_len) == arr[i]){
            dp[len] = dp[len] || go(len + word_len);
        }
    }

    return dp[len];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> s >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << go(0);
}