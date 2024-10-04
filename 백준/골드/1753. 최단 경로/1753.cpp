#include <bits/stdc++.h>
#define INF 99999999

using namespace std;

int v, e, k;
vector<pair<int, int>> graph[20010];
int d[20010];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> v >> e;

    cin >> k;

    for(int i = 0; i < e; ++i){
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
    }

    for(int i = 1; i <= v; ++i){
        d[i] = INF;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, k});
    d[k] = 0;

    while(pq.size()){
        int curNode = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        if(d[curNode] < curDist) continue;

        for(pair<int, int> v: graph[curNode]){
            int next = v.first;
            int dist = v.second + curDist;

            if(dist < d[next]){
                d[next] = dist;
                pq.push({dist, next});
            }
        }
    }

    for(int i = 1; i <= v; ++i){
        if(d[i] == INF){
            cout << "INF";
        }else{
            cout << d[i];
        }
        cout << '\n';
    }
}
