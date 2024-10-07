#include <bits/stdc++.h>

using namespace std;

int parent[500001];
int n, m;

int find(int a){
    if(a == parent[a]) return a;

    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;

    if(a < b){
        parent[b] = a;
        return;
    }

    parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; ++i){
        parent[i] = i;
    }

    bool flag = false;
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;

        if(find(a) == find(b)){
            flag = true;
            cout << i + 1;
            break;
        }else{
            merge(a, b);
        }
    }
    if(!flag) cout << 0;
}