#include <bits/stdc++.h>

using namespace std;

int n, m;
int parent[1000001];

int find(int v){
    if(v == parent[v]) return parent[v];

    return parent[v] = find(parent[v]);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);

    if(x < y){
        parent[y] = x;
        return;
    }
    parent[x] = y;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        parent[i] = i;
    }

    for(int i = 0; i < m; ++i){
        int command, a, b;
        cin >> command >> a >> b;

        if(command == 0){
            merge(a, b);
        }else if(command == 1){
            if(find(a) == find(b)){
                cout << "YES";
            }else{
                cout << "NO";
            }
            cout << '\n';
        }
    }
}