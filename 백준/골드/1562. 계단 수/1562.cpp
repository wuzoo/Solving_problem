#include <bits/stdc++.h>

using namespace std;

int dp[10][101][1024];
int n;

int dfs(int k, int digit, int bit){
    if(dp[k][digit][bit] != 0) return dp[k][digit][bit];
    
    if(digit == n){
        if(bit == 1023) return 1;
        else return 0;
    }

    int cnt = 0;
    if(k < 9){
        cnt += dfs(k + 1, digit + 1, (bit | 1 << (k + 1)));
    }
    if(k > 0){
        cnt += dfs(k - 1, digit + 1, (bit | 1 << (k - 1)));
    }
    cnt %= 1000000000;

    return dp[k][digit][bit] = cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    int ans = 0;
    for(int i = 1; i <= 9; ++i){
        ans += dfs(i, 1, (1 << i));
        ans %= 1000000000;
    }
    

    cout << ans;
}