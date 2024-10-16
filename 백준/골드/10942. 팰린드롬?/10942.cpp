#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[2001];
int dp[2001][2001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    for(int i = 2; i < n; ++i){
        for(int j = 1; i - j > 0 && i + j <= n; ++j){
            if(arr[i - j] == arr[i + j]) dp[i - j][i + j] = 1;
            else break;
        }
    }

    for(int i = 2; i < n; ++i){
        if(arr[i] != arr[i + 1]) continue;
        for(int j = 1; i - j > 0 && i + j + 1 <= n; ++j){
            if(arr[i - j] == arr[i + j + 1]) dp[i - j][i + j + 1] = 1;
            else break;
        }
    }

    cin >> m;

    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;

        if(b - a == 1){
            if(arr[a] == arr[b]) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(b - a == 0){
            cout << 1 << '\n';
        }else{
            cout << dp[a][b] << '\n';
        }
    }
}