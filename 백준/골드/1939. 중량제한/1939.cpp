#include <bits/stdc++.h>
#define INF 1000000001
using namespace std;

int n, m;
int v1, v2;
vector<pair<int, int>> graph[10001];
int visited[10001];
int ans;

bool bfs(int mid){
    queue<int> q;
    vector<int> visited(n + 1, 0);
    q.push(v1);
    visited[v1] = 1;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        if(v == v2) return true;

        for(auto s: graph[v]){
            int nc = s.first;
            int nv = s.second;
            
            if(visited[nv]) continue;
            if(nc < mid) continue;

            visited[nv] = 1;
            q.push(nv);
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    cin >> v1 >> v2;

    int st = 1;
    int en = INF;
    while(st <= en){
        int mid = (st + en) / 2;

        if(bfs(mid)){ 
            ans = max(ans, mid);
            st = mid + 1;
        }else{
            en = mid - 1;
        }
    }

    cout << ans;
}