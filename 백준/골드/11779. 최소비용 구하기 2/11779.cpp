#include <bits/stdc++.h>
#define INF 100000001
using namespace std;

int n, m;
vector<pair<int, int>> graph[1001];
int d[1001];
int a, b;
int route[1001];

void dikjstra(int v){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, v});
    d[v] = 0;

    while(!q.empty()){
        int curNode = q.top().second;
        int curDist = q.top().first;

        q.pop();

        if(d[curNode] < curDist) continue;

        for(auto s: graph[curNode]){
            int next = s.second;
            int dist = s.first + curDist;

            if(dist < d[next]){
                d[next] = dist;
                route[next] = curNode;
                q.push({dist, next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int v, w, c; cin >> v >> w >> c;

        graph[v].push_back({c, w});
    }
    cin >> a >> b;
    for(int i = 1; i <= n; ++i){
        d[i] = INF;
    }

    dikjstra(a);

    int node = b;
    int idx = 0;
    vector<int> result;
    while(node){
        result.push_back(node);
        node = route[node];
        idx++;
    }
    
    cout << d[b] << '\n' << result.size() << '\n';
    for(int i = result.size() - 1; i >= 0; --i){
        cout << result[i] << ' ';
    }
}