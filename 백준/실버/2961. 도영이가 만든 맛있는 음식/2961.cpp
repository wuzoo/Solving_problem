#include <bits/stdc++.h>
#define INF 1000000001
using namespace std;

int n;
vector<pair<int, int>> v;
int visited[11];
int ans = INF;

void dfs(int k, int fsum, int ssum){
    if(k != 0){
        ans = min(ans, abs(fsum - ssum));
    }

    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            visited[i] = 1;
            dfs(k + 1, fsum * v[i].first, ssum + v[i].second);
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;

        v.push_back({a, b});
    }

    dfs(0, 1, 0);

    cout << ans;
}