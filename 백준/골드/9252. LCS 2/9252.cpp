#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string a, b;
    cin >> a >> b;

    for(int i = 1; i <= a.length(); ++i){
        for(int j = 1; j <= b.length(); ++j){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    
    string lcs = "";
    int idx = b.length();
    for(int i = a.length(); i >= 1; i--){
        for(int j = idx; j >= 1; j--){
            if(dp[i][j] == dp[i - 1][j]){
                idx = j;
                break;
            }else if(dp[i][j] == dp[i][j - 1]){
                continue;
            }else{ 
                lcs = a[i - 1] + lcs;
            }
        }
    }

    cout << dp[a.length()][b.length()] << '\n' << lcs;
}