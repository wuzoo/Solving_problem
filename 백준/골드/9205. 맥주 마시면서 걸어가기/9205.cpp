#include <bits/stdc++.h>
using namespace std;

int visited[101];
int home_x, home_y, dest_x, dest_y;
vector<pair<int, int>> store;

struct Node{
    int x, y, cur_distance;
};

int get_distance(int x, int y, int dx, int dy){
    return abs(x - dx) + abs(y - dy);
}

bool bfs(int x, int y){
    queue<Node> q;
    q.push({x, y, get_distance(x, y, dest_x, dest_y)});
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cur_distance = q.front().cur_distance;
        q.pop();

        if(cur_distance <= 20 * 50){
            cout << "happy" << endl;
            return true;
        }

        for(int i = 0; i < store.size(); ++i){
            int distance = get_distance(x, y, store[i].first, store[i].second);

            if(distance <= 20 * 50 && !visited[i]){
                int distance_to_dest = get_distance(store[i].first, store[i].second, dest_x, dest_y);

                visited[i] = 1;
                q.push({store[i].first, store[i].second, distance_to_dest});
            }
        }
    }
    cout << "sad" << endl;
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        cin >> home_x >> home_y;

        for(int i = 0; i < n; ++i){
            int x, y; cin >> x >> y;
            
            store.push_back({x, y});
        }

        cin >> dest_x >> dest_y;

        bfs(home_x, home_y);
        memset(visited, 0, sizeof(visited));
        store.clear();
    }
}