#include <bits/stdc++.h>

using namespace std;
long long dp[31][31];

long long go(int w, int h){
    if(dp[w][h] != -1) return dp[w][h];

    if(w == 0 && h == 0) return 1;

    long long cnt = 0;

    if(w < 0 || h < 0) return 0;

    if(h > 0){
        cnt += go(w, h - 1);
    }
    if(w > 0){
        cnt += go(w - 1, h + 1);
    }

    return dp[w][h] = cnt;
}   

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int input;
    while(true){
        cin >> input;
        if(input == 0) break;

        memset(dp, -1, sizeof(dp));

        cout << go(input, 0) << '\n';
    }
}