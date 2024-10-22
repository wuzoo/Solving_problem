#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1000001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; ++i){
        if(i % 2 != 0){
            dp[i] = dp[i - 1] % 1000000000;
        }else{
            dp[i] = ( dp[i / 2] + dp[i - 1] ) % 1000000000;
        }
    }

    cout << dp[n];

}