#include <bits/stdc++.h>

using namespace std;

int n, m;
char graph[1001][1001];
int visited[1001][1001];
pair<int, int> parent[1001][1001];

pair<int, int> find(int x, int y){
    if(parent[x][y] == pair<int, int>(x, y)) return pair<int, int>(x, y);

    return parent[x][y] = find(parent[x][y].first, parent[x][y].second);
}

void merge(int x1, int y1, int x2, int y2){
    pair<int, int> p1 = find(x1, y1);
    pair<int, int> p2 = find(x2, y2);

    if(p1.first == p2.first && p1.second == p2.second) return;

    if(p1.first < p2.first){
        parent[p2.first][p2.second] = p1;
    }
    else if(p1.first > p2.first){
        parent[p1.first][p1.second] = p2;
    }
    else if(p1.second < p2.second){
        parent[p2.first][p2.second] = p1;
    }
    else{
        parent[p1.first][p1.second] = p2;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> m >> n;

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            char c;
            cin >> c;
            graph[j][i] = c;

            parent[j][i] = {j, i};
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(graph[i][j] == 'D') merge(i, j, i, j + 1);
            else if(graph[i][j] == 'R') merge(i, j, i + 1, j);
            else if(graph[i][j] == 'U') merge(i, j, i, j - 1);
            else merge(i, j, i - 1, j);
        }
    }

    set<pair<int, int>> s;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            s.insert(find(i, j));
        }
    }

    cout << s.size() << '\n';
}