#include <bits/stdc++.h>

using namespace std;

int n, m;
pair<int, int> pos[1001];
vector<pair<double, pair<int, int>>> graph;
int parent[1001];

int find(int v){
    if(v == parent[v]) return v;

    return parent[v] = find(parent[v]);
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

    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        int a, b;
        cin >> a >> b;

        pos[i] = {a, b};

        parent[i] = i;
    }
    
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;

        merge(a, b);
    }
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            if(i == j) continue;

            double dist = sqrt(pow((pos[i].first - pos[j].first), 2) + pow((pos[i].second - pos[j].second), 2));

            graph.push_back({dist, {i, j}});
        }
    }

    sort(graph.begin(), graph.end());

    double sum = 0;
    for(auto v: graph){
        int st = v.second.first;
        int en = v.second.second;
        double d = v.first;

        if(find(st) != find(en)){
            merge(st, en);
            sum += d;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << sum;
}