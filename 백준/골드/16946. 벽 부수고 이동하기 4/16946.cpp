#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m, numbering = 1;
int graph[1001][1001];
int result[1001][1001];
int zeroCnts[1001][1001];

vector<int> zero_size;

void bfs(int x, int y){
    queue<pair<int, int>> q;

    q.push({x, y});
    zeroCnts[x][y] = numbering;
    int cnt = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int j = 0; j < 4; ++j){
            int nx = x + dx[j];
            int ny = y + dy[j];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(graph[nx][ny] == 1) continue;
            if(zeroCnts[nx][ny]) continue;
            
            zeroCnts[nx][ny] = numbering;
            cnt++;
            q.push({nx, ny});
        }
    }

    zero_size.push_back(cnt);
    numbering++;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
   
    cin >> n >> m;
    vector<pair<int, int>> v;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char c;
            cin >> c;
            graph[i][j] = c - '0';

            if(c - '0' == 1) v.push_back({i, j});
        }
    }

    zero_size.push_back(0);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(graph[i][j] == 0 && !zeroCnts[i][j]){
                bfs(i, j);
            }
        }
    }

    for(int i = 0; i < v.size(); ++i){
        int x = v[i].first;
        int y = v[i].second;

        set<int> s;

        for(int j = 0; j < 4; ++j){
            int nx = x + dx[j];
            int ny = y + dy[j];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(zeroCnts[nx][ny] == 0) continue;

            s.insert(zeroCnts[nx][ny]);
        }

        for(auto e: s){
            result[x][y] += zero_size[e];
        }
        
        result[x][y] += 1;
        result[x][y] %= 10;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << result[i][j];
        }
        cout << '\n';
    }
}