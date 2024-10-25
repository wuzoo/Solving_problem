#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> graph[50001];
int d[50001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b; int c;
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    for(int i = 1; i <= n; ++i){
        d[i] = 1e9;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    d[1] = 0;

    while(q.size()){
        int curNode = q.top().second;
        int curDist = q.top().first;
        q.pop();

        if(d[curNode] < curDist) continue;

        for(int i = 0; i < graph[curNode].size(); ++i){
            int next = graph[curNode][i].second;
            int dist = curDist + graph[curNode][i].first;

            if(dist < d[next]){
                d[next] = dist;
                q.push({dist, next});
            }
        }
    }

    cout << d[n];
}   