#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int n, m, k;
int graph[1001][1001];
int visited[1001][1001];
vector<pair<int, int>> ans;
priority_queue<pair<int, pair<int, int>>> q;

void BFS(){
    while(!q.empty()){
        int x = q.top().second.first;
        int y = q.top().second.second;
        int value = q.top().first;
        q.pop();

        ans.push_back({x, y});

        if(ans.size() == k){
            break;
        }

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny]) continue;

            visited[nx][ny] = 1;
            q.push({graph[nx][ny], {nx, ny}});
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> graph[i][j];

            if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                q.push({graph[i][j], {i, j}});
                visited[i][j] = 1;
            }
        }
    }

    cin >> k;

    BFS();

    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }
}