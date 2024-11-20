#include <bits/stdc++.h>

using namespace std;

long long sum[1000001];
long long result[1000001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    for(int i = 1; i <= 1000000; ++i){
        sum[i] += i;
        for(int j = i + i; j <= 1000000; j += i){
            sum[j] += i;
        }
    }

    for(int i = 1; i <= 1000000; ++i){
        result[i] = result[i - 1] + sum[i];
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << result[n] << '\n';
    }
}