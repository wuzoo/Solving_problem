#include <bits/stdc++.h>

using namespace std;

int n;
char arr[1001];
int dp[1001][3];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for(int i = 1; i <= n; ++i){
        char c;
        cin >> c;
        arr[i] = c;

        dp[i][0] = 1000001;
        dp[i][1] = 1000001;
        dp[i][2] = 1000001;
    }

    dp[1][0] = 0;

    for(int i = 1; i <= n; ++i){
        char current = arr[i];

        for(int j = 1; j < i; ++j){
            if(current == 'B'){
                if(arr[j] == 'J'){
                    int cost = pow(i - j, 2);

                    dp[i][0] = min(dp[i][0], dp[j][2] + cost);
                }
            }
            if(current == 'O'){
                if(arr[j] == 'B'){
                    int cost = pow(i - j, 2);

                    dp[i][1] = min(dp[i][1], dp[j][0] + cost);
                }
            }
            if(current == 'J'){
                if(arr[j] == 'O'){
                    int cost = pow(i - j, 2);

                    dp[i][2] = min(dp[i][2], dp[j][1] + cost);
                }
            }
        }
    }

    int mn = 1000001;
    for(int i = 0; i < 3; ++i){
        mn = min(mn, dp[n][i]);
    }

    if(mn == 1000001) cout << -1;
    else cout << mn;
}