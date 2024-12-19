#include <bits/stdc++.h>

using namespace std;

vector<string> dp[12];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, k; cin >> n >> k;

    dp[1].push_back("1");
    dp[2].push_back("1+1"); dp[2].push_back("2");
    dp[3].push_back("1+1+1"); dp[3].push_back("2+1"); dp[3].push_back("1+2"); dp[3].push_back("3");
    
    for(int i = 4; i <= n; ++i){
        for(int j = 0; j < dp[i - 1].size(); ++j){
            string str = dp[i - 1][j] + "+1";
            dp[i].push_back(str);
        }
        for(int j = 0; j < dp[i - 2].size(); ++j){
            string str = dp[i - 2][j] + "+2";
            dp[i].push_back(str);
        }
        for(int j = 0; j < dp[i - 3].size(); ++j){
            string str = dp[i - 3][j] + "+3";
            dp[i].push_back(str);
        }
    }

    sort(dp[n].begin(), dp[n].end());

    if(dp[n].size() < k){
        cout << -1;
    }else{
        cout << dp[n][k - 1];
    }
}