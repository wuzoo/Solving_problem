#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> graph[10001];
int visited[10001];

int dfs(int v){
    int cnt = 1;

    for(int i = 0; i < graph[v].size(); ++i){
        if(visited[graph[v][i]]) continue;

        visited[graph[v][i]] = 1;
        cnt += dfs(graph[v][i]);
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;

        graph[b].push_back(a);
    }

    vector<pair<int, int>> result;
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        visited[i] = 1;
        int hacking_num = dfs(i);

        result.push_back({i, hacking_num});
        ans = max(ans, hacking_num);
        
        memset(visited, 0, sizeof(visited));
    }

    sort(result.begin(), result.end());

    for(int i = 0; i < result.size(); ++i){
        pair<int, int> s = result[i];

        if(ans == result[i].second){
            cout << result[i].first << ' ';
        }
    }   
}