#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> graph[10001];
int visited[10001];

int bfs(int v){
    queue<pair<int, int>> q;
    q.push({v, 0});
    visited[v] = 1;
    int len = 0;
    
    while(!q.empty()){
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        len = max(len, dist);

        for(int i = 0; i < graph[cur].size(); ++i){
            int next = graph[cur][i].first;
            int cost = graph[cur][i].second + dist;

            if(visited[next]) continue;

            visited[next] = 1;
            q.push({next, cost});
        }
    }

    return len;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n - 1; ++i){
        int p, c, d;
        cin >> p >> c >> d;

        graph[p].push_back({c, d});
        graph[c].push_back({p, d});
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans = max(ans, bfs(i));
        memset(visited, 0, sizeof(visited));
    }

    cout << ans;
}