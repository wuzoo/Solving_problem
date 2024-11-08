#include <bits/stdc++.h>
#define INF 1000001
using namespace std;

int n, p, k;
vector<pair<int, int>> graph[1001];
int dis[1001];
int ans = -1;

bool dijkstra(int x){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    dis[1] = 0;

    while(!q.empty()){
        int curNode = q.top().second;
        int curDist = q.top().first;
        q.pop();

        if(dis[curNode] < curDist) continue;

        for(int i = 0; i < graph[curNode].size(); ++i){
            int v = graph[curNode][i].second;
            int dist = graph[curNode][i].first;
            int nxtcost = curDist + (dist > x);

            if(nxtcost < dis[v]){
                q.push({nxtcost, v});
                dis[v] = nxtcost;
            }
        }
    }

    return dis[n] <= k;
}
/**
 * x원으로 연결 가능하다 = 가중치가 x원 이하의 것들만 포함시키거나, x원보다 큰 것들은 k개 이하로 포함시킨다.
 * 가능한 것들 중 최소의 x를 구하라.
 */

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> p >> k;   

    for(int i = 0; i < p; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    for(int i = 1; i <= n; ++i){
        dis[i] = INF;
    }

    int st = 0;
    int en = 1000000;

    while(st <= en){
        int mid = (st + en) / 2;
        memset(dis, 1000001, sizeof(dis));
 
        if(dijkstra(mid)){
            ans = mid;
            en = mid - 1;
        }else{
            st = mid + 1;
        }
    }

    cout << ans;
}