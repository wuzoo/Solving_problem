#include <bits/stdc++.h>

using namespace std;

int n, m;
int parent[201];

int find(int v){
    if(v == parent[v]) return v;

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

    for(int i = 1; i <= n; ++i){
        
        for(int j = 1; j <= n; ++j){
            int num;
            cin >> num;

            if(num == 1){
                merge(i, j);
            }
        }
    }

    vector<int> v;
    for(int i = 0; i < m; ++i){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    int flag = true;
    for(int i = 0; i < v.size() - 1; ++i){
        if(find(v[i]) != find(v[i + 1])){
            flag = false;
            break;
        }
    }

    if(flag){
        cout << "YES";
    }else{
        cout << "NO";
    }
}