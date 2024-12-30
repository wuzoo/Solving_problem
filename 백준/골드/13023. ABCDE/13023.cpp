#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> graph[2001];
int visited[2001];
int ans;

void dfs(int k, int v){ // 
    if(k == 5){
        ans = 1;
        return;
    }

    for(auto s: graph[v]){
        if(!visited[s]){
            visited[s] = 1;
            dfs(k + 1, s);
            visited[s] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i = 0; i < n; ++i){
        visited[i] = 1;
        dfs(1, i);
        visited[i] = 0;

        if(ans){
            cout << ans;
            return 0;
        }
    }

    cout << 0;
}