#include <bits/stdc++.h>

using namespace std;

int n, m;
int parent[201];

int find(int x){
    if(x == parent[x]) return x;

    return parent[x] = find(parent[x]);
}

void Union(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(x < y){
        parent[y] = x;
        return;
    }

    parent[x] = y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
	
	for(int i =1 ; i <= n; i++) parent[i] = i;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int x;
			cin >> x;
			if(x == 1) {
				Union(i,j);
			}
		}
	}

    vector<int> route;
    for(int i = 0; i < m; ++i){
        int v;
        cin >> v;
        route.push_back(v);
    }

    int flag = false;
    int root = 0;
    for(int i = 0; i < m; ++i){
        if(i == 0) root = find(route[i]);
        else{
            if(root != find(route[i])){
                cout << "NO";
                flag = true;
                break;
            }
        }
    }
    if(!flag) cout << "YES";
}