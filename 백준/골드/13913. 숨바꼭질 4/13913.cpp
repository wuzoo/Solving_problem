#include <bits/stdc++.h>

using namespace std;
int n, k;
int visited[100001];
int route[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;

    queue<pair<int, int>> q;
    q.push({0, n});
    visited[n] = 1;

    while(!q.empty()){
        int time = q.front().first;
        int pos = q.front().second;
        q.pop();

        if(pos == k){
            cout << time << '\n';
            vector<int> v;
            int idx = k;

            v.push_back(k);
            while(idx != n){
                v.push_back(route[idx]);
                idx = route[idx];
            }

            for(int i = v.size() - 1; i >= 0; --i){
                cout << v[i] << ' ';
            }
            break;
        }

        if(pos + 1 <= 100000 && !visited[pos + 1]){
            visited[pos + 1] = 1;
            route[pos + 1] = pos;
            q.push({time + 1, pos + 1});
        }

        if(pos - 1 >= 0 && !visited[pos - 1]){
            visited[pos - 1] = 1;
            route[pos - 1] = pos;
            q.push({time + 1, pos - 1});
        }

        if(2 * pos <= 100000 && !visited[2 * pos]){
            visited[pos * 2] = 1;
            route[pos * 2] = pos;
            q.push({time + 1, pos * 2});
        }
    }
}