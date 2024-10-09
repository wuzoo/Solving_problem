#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<pair<int, int>, int>> edges;
int parent[100001];

struct cmp{
    bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
        return a.second < b.second;
    }
};

int find(int a){
    if(a == parent[a]) return a;

    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;

    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back({{a, b}, c});
    }   
    for(int i = 1; i <= n; ++i){
        parent[i] = i;
    }

    sort(edges.begin(), edges.end(), cmp());

    int ans = 0;
    int max_edge = 0;
    for(int i = 0; i < m; ++i){
        int a = edges[i].first.first;
        int b = edges[i].first.second;
        int c = edges[i].second;

        if(find(a) == find(b)) continue;

        max_edge = max(max_edge, c);
        merge(a, b);

        ans += c;
    }

    cout << ans - max_edge << '\n';
}