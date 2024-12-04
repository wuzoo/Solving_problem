#include <bits/stdc++.h>

using namespace std;

int parent[1001];
vector<pair<int, pair<int, int>>> graph;

int find(int x){
    if(x == parent[x]) return x;

    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(a < b){
        parent[b] = a;
        return;
    }

    parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        graph.push_back({c, {a, b}});
    }

    for(int i = 1; i <= n; ++i){
        parent[i] = i;
    }

    sort(graph.begin(), graph.end());

    int sum = 0;
    for(auto s: graph){
        if(find(s.second.first) == find(s.second.second)) continue;

        merge(s.second.first, s.second.second);
        sum += s.first;
    }

    cout << sum;
}