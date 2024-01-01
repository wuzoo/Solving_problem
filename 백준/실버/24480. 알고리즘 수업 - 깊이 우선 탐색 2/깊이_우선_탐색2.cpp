#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r;
vector<int> graph[100001];
int visited[100001];
int result[100001];
int cur = 1;

void dfs(int ver){
    visited[ver] = 1;
    result[ver] = cur++;
    
    for(int i = 0; i < graph[ver].size(); ++i){
        int v = graph[ver][i];
        if(!visited[v]){
            dfs(v);
        }
    }
}
bool cmp(int i, int j){
    return i > j;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> r;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i){
        sort(graph[i].begin(), graph[i].end(), cmp);
    }

    dfs(r);

    for(int i = 1; i <= n; ++i){
        cout << result[i] << '\n';
    }

    return 0;
}