#include <bits/stdc++.h>

using namespace std;

int v, e;
vector<pair<pair<int, int>, long long>> arr;
int parent[10001];

int find(int a ){
    if(a == parent[a])return a;

    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b)return;

    if(a < b) parent[b] = a;
    else parent[a] = b;
}

struct cmp{
    bool operator()(pair<pair<int, int>, long long> a, pair<pair<int, int>, long long> b){
        return a.second < b.second;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> v >> e;

    for(int i = 0; i < e; ++i){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        arr.push_back({{a, b}, c});
    }

    for(int i = 1; i <= v; ++i){
        parent[i] = i;
    }

    sort(arr.begin(), arr.end(), cmp());

    long long sum = 0;
    for(int i = 0; i < arr.size(); ++i){
        int a = arr[i].first.first;
        int b = arr[i].first.second;
        long long c = arr[i].second;

        if(find(a) == find(b)) continue;

        merge(a, b);
        sum += c;
    }

    cout << sum << '\n';
}