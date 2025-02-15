#include <bits/stdc++.h>

using namespace std;

long long time_table[100001];
long long sum[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, t; cin >> n >> t;

    int max_endtime = 0;
    for(int i = 0; i < n; ++i){
        int k; cin >> k;
        for(int j = 0; j < k; ++j) {
            int s, e; cin >> s >> e;
            time_table[s]++;
            time_table[e]--;
        }
    }

    for(int i = 0; i <= 100000; ++i){
        time_table[i] += time_table[i - 1];
    }
    
    for(int i = 0; i <= 100000; ++i){
        if(i == 0) sum[i] = time_table[i];
        else{
            sum[i] = sum[i - 1] + time_table[i];
        }
    }
    
    pair<long long, long long> ans = {0, t};
    long long max_value = sum[t - 1];

    for(int i = 0; i <= 100000; ++i){
        if(max_value < sum[t - 1 + i] - sum[i - 1]){
            max_value = sum[t - 1 + i] - sum[i - 1];
            ans = {i, t + i};
        }
    }
    cout << ans.first << ' ' << ans.second;
}