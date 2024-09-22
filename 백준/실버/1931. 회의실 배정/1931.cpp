#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }

    sort(v.begin(), v.end());

    int num = 1;
    int end = v[0].first;
    for(int i = 1; i < n; ++i){
        if(end <= v[i].second){
            num++;
            end = v[i].first;
        }
    }

    cout << num;
}