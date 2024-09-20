#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph(100001);
int n, m;
int degree[100001];
int result[100001];
void topology(){
    queue<int> q;

    for(int i = 1; i <= n; ++i){
        if(degree[i] == 0) q.push(i);
    }

    for(int i = 1; i <= n; ++i){
        int current = q.front();
        q.pop();
        result[i] = current;
        for(int i = 0; i < graph[current].size(); ++i){
            int next = graph[current][i];

            if(--degree[next] == 0) q.push(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        degree[b]++;
    }

    topology();

    for(int i = 1; i <= n; ++i){
        cout << result[i] << ' ';
    }
}