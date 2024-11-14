#include <bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int > b){
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> v;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; ++i){
        q.push(v[i]);

        if(!q.empty() && q.top().second <= v[i].first){
            q.pop();
        }
    }

    cout << q.size();
}