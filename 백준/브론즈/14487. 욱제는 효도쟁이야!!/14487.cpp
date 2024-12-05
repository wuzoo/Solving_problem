#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<int, int> m;

    int mx_d = 0;
    int mx_num = 0;
    for(int i = 1; i <= n; ++i){
        int d;
        cin >> d;

        m.insert({i, d});

        if(mx_d < d){
            mx_num = i;
            mx_d = d;
        }
    }

    int sum = 0;
    for(int i = 1; i <= n; ++i){
        if(i == mx_num) continue;

        sum += m[i];
    }

    cout << sum;
}