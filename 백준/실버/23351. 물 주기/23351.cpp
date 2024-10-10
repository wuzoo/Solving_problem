#include <bits/stdc++.h>

using namespace std;

int n, k, a, b;
vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    
    cin >> n >> k >> a >> b;

    for(int i = 0; i < n; ++i){
        v.push_back(k);
    }

    int day = 0;
    while(true){
        if(v[0] == 0){
            cout << day;
            break;
        }

        for(int j = 0; j < a; ++j){
            v[j] += b;
        }

        for(int j = 0; j < n; ++j){
            v[j]--;
        }

        sort(v.begin(), v.end());
        day++;
    }
}