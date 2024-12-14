#include <bits/stdc++.h>

using namespace std;

struct node{
    int val = 1;
    vector<int> edge;
}arr[11];

int visited[11];

int gcd(int a, int b){
    if(b == 0) return a;

    return gcd(b, a % b);
}

void dfs(int v, int mod){
    arr[v].val *= mod;
    visited[v] = 1;
    for(auto s: arr[v].edge){
        if(!visited[s]){
            dfs(s, mod);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;

    for(int i = 0; i < n - 1; ++i){
        int a, b, p, q; cin >> a >> b >> p >> q;

        int amod = arr[b].val * p / gcd(p, q);
        int bmod = arr[a].val * q / gcd(p, q);

        dfs(a, amod / gcd(amod, bmod));
        dfs(b, bmod / gcd(amod, bmod));

        memset(visited, 0, sizeof(visited));

        arr[a].edge.push_back(b);
        arr[b].edge.push_back(a);
    }

    for(int i = 0; i <= n - 1; ++i){
        cout << arr[i].val << ' ';
    }
}