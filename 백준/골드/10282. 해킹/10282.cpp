#include <bits/stdc++.h>
#define INF 100000001

using namespace std;

vector<pair<int, int>> graph[10001];
int d[10001];

void dijkstra(int v){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, v});
    d[v] = 0;

    while(!q.empty()){
        int curDist = q.top().first;
        int curNode = q.top().second;
        q.pop();

        if(d[curNode] < curDist) continue;

        for(int i = 0; i < graph[curNode].size(); ++i){
            int next = graph[curNode][i].second;
            int cost = curDist + graph[curNode][i].first;

            if(cost < d[next]){
                d[next] = cost;
                q.push({cost, next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, dc, c;
        cin >> n >> dc >> c;

        for(int i = 0; i < dc; ++i){
            int a, b, s;
            cin >> a >> b >> s;

            graph[b].push_back({s, a});
        }

        for(int i = 1; i <= n; ++i){
            d[i] = INF;
        }

        dijkstra(c);

        int cnt = 0;
        int total = 0;
        for(int i = 1; i <= n; ++i){
            if(d[i] != INF){
                cnt++;
                total = max(total, d[i]);
            }
        }

        cout << cnt << ' ' << total << '\n';
        
        for(int i = 1; i <= n; ++i){
            graph[i].clear();
        }
    }
}