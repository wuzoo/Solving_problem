#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int parent[30001];
pair<int, int> group[30001];
int dp[30001][3001];


int find(int n){
    if(n == parent[n]) return n;

    return parent[n] = find(parent[n]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(a < b){
        parent[b] = a;
        return;
    }

    parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; ++i){
        parent[i] = i;
    }

    vector<int> value;
    value.push_back(0);
    for(int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        value.push_back(a);
    }

    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;

        merge(a, b);
    }

    for(int i = 1; i <= n; ++i){
        int i_parent = find(i);

        group[i_parent].second += value[i];      
        group[i_parent].first++;  
    }

    vector<pair<int, int>> arr;
    arr.push_back({});
    for(int i = 1; i <= n; ++i){
        if(group[i].second != 0){
            arr.push_back(group[i]);
        }
    }

    for(int i = 1; i < arr.size(); ++i){
        for(int j = 1; j < k; ++j){
            dp[i][j] = dp[i - 1][j];

            if(j - arr[i].first >= 0){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j- arr[i].first] + arr[i].second);
            }
        }
    }

    cout << dp[arr.size() - 1][k - 1];
}