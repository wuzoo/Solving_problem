#include <bits/stdc++.h>

using namespace std;

int parent[1000001];

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

    int t;
    cin >> t;

    int round = 1;
    while(t--){
        int n, k;
        cin >> n >> k;

        for(int i = 0; i < n; ++i){
            parent[i] = i;
        }

        for(int i = 0; i < k; ++i){
            int a, b;
            cin >> a >> b;

            merge(a, b);
        }

        int m;
        cin >> m;

        cout << "Scenario " << round << ":" << '\n';
        for(int i = 0; i < m; ++i){
            int u, v;
            cin >> u >> v;

            if(find(u) == find(v)) cout << 1;
            else cout << 0;
            cout << '\n';
        }
        
        cout << '\n';
        round++;
        memset(parent, 0, sizeof(parent));
    }
}