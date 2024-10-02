#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1001];
int inDegree[1001];
int cost[1001];
int result[1001];

int n, k;

void topology(){
    queue<int> q;

    for(int i = 1; i <= n; ++i){
        if(inDegree[i] == 0){
            q.push(i);
        }
        result[i] = cost[i];
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int next : graph[cur]){
            inDegree[next]--;
            result[next] = max(result[next], result[cur] + cost[next]);

            if(inDegree[next] == 0){
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        cin >> n >> k;
        
        for(int i = 1; i <= n; ++i){
            cin >> cost[i];
        }

        for(int i = 0; i < k; ++i){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            inDegree[b]++;
        }
        
        int w;
        cin >> w;

        topology();

        cout << result[w] << '\n';

        memset(graph, 0, sizeof(graph));
        memset(inDegree, 0, sizeof(inDegree));
        memset(cost, 0, sizeof(cost));
        memset(result, 0, sizeof(result));
    }
}