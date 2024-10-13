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
        v.push_back({a, b});
    }
    
    long double sum = 0;
    for(int i = 0; i < n; ++i){
        long double xi = v[i].first;
        long double yi = v[i].second;
        long double nxi;
        long double nyi;
        if(i == n - 1){
            nxi = v[0].first;
            nyi = v[0].second;
        }else{
            nxi = v[i + 1].first;
            nyi = v[i + 1].second;
        }

        sum += ((xi + nxi) * (yi - nyi));
    }
    
    cout << fixed;
    cout.precision(1);
    cout << abs(sum) / 2;
}