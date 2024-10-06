#include <bits/stdc++.h>

using namespace std;

int n, m;
int degree[1001];
vector<int> graph[1001];
vector<int> result;

void topology(){
    queue<int> q;

    for(int i = 1; i <= n; ++i){
        if(degree[i] == 0){
            q.push(i);
        }
    }

    while(q.size()){
        int cur = q.front();
        q.pop();

        result.push_back(cur);
        for(int i = 0; i < graph[cur].size(); ++i){
            if(--degree[graph[cur][i]] == 0){
                q.push(graph[cur][i]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int cnt;
        cin >> cnt;

        vector<int> temp;
        for(int j = 0; j < cnt; ++j){ 
            int num;
            cin >> num;
            temp.push_back(num);
        }
        for(int j = 0; j < temp.size(); ++j){
            for(int k = j + 1; k < temp.size(); ++k){
                graph[temp[j]].push_back(temp[k]);
                degree[temp[k]]++;
            }
        }
    }

    topology();

    if(result.size() != n){
        cout << 0 << '\n';
    }else{
        for(int i = 0; i < result.size(); ++i){
            cout << result[i] << '\n';
        }        
    }
}