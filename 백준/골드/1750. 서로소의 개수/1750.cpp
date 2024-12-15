#include <bits/stdc++.h>

using namespace std;

int arr[51];
long long dp[1000001];

int gcd(int a, int b){
    if(b == 0) return a;

    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= 100000; ++j){
            if(dp[j]){
                dp[gcd(arr[i], j)] += dp[j];
            }
        }
        dp[arr[i]] += 1;
    }
    
    cout << dp[1] % 10000003;
}