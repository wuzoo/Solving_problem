#include <bits/stdc++.h>

using namespace std;

int n;
int graph[21][21];
vector<int> start;
int visited[21];
int ans = 10001;

void dfs(int k, int idx){
    if(k == n / 2){
        int tmp[21] = {};

        int sum_start = 0;
        for(int i = 0; i < start.size(); ++i){
            int first = start[i];
            tmp[first] = 1;
            for(int j = i + 1; j < n / 2; ++j){
                int second = start[j];

                sum_start += graph[first][second];
                sum_start += graph[second][first];
            }
        }
        vector<int> link;
        for(int i = 1; i <= n; ++i){
            if(tmp[i] != 1){
                link.push_back(i);
            }
        }
        
        int sum_link = 0;
        for(int i = 0; i < link.size(); ++i){
            int first = link[i];
            for(int j = i + 1; j < link.size(); ++j){
                int second = link[j];

                sum_link += graph[first][second];
                sum_link += graph[second][first];
            }
        }

        ans = min(ans, abs(sum_start - sum_link));

        return;
    }
    for(int i = idx; i <= n; ++i){
        if(!visited[i]){
            visited[i] = 1;
            start.push_back(i);
            dfs(k + 1, i);
            start.pop_back();
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> graph[i][j];
        }
    }

    dfs(0, 1);

    cout << ans;
}