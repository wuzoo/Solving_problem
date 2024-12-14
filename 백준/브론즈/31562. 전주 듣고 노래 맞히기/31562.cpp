#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m;
    unordered_map<string, string> map;

    for(int i = 0; i < n; ++i){
        int t; string s; string a = ""; cin >> t >> s;

        for(int j = 0; j < 7; ++j){
            char c; cin >> c;
            
            if(j >= 3) continue;
            a += c;
        }
        map.insert({s, a});
    }

    for(int i = 0; i < m; ++i){
        string tmp = "";
        for(int j = 0; j < 3; ++j){
            char c; cin >> c;

            tmp += c;
        }

        int cnt = 0; string name = "";
        for(auto s: map){
            if(cnt > 1) break;
            if(s.second == tmp){
                name = s.first;
                cnt++;
            }
        }
        if(cnt > 1) cout << "?\n";
        else if(cnt == 1) cout << name << '\n';
        else cout << "!\n";
    }
}