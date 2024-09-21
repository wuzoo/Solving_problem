#include <bits/stdc++.h>

using namespace std;

int dp[101];

bool cmp(const pair<int, int>& l, const pair<int, int>& r){
    return l.first < r.first;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> arr;

    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end(), cmp);

    for(int i = 0; i < arr.size(); ++i){
        dp[i] = 1;
        for(int j = 0; j < i; ++j){
            if(arr[i].second > arr[j].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int mx = 0;
    for(int i = 0; i < arr.size(); ++i){
        mx = max(mx, dp[i]);
    }

    cout << n - mx;
}