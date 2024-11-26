#include <bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator()(string a, string b){
        return a.length() < b.length();
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin>> t;
    while(t--){
        int n;
        cin >> n;

        vector<string> v;
        for(int i = 0; i < n; ++i){
            string s;
            cin >> s;
            v.push_back(s);
        }

        set<string> hs;
        sort(v.begin(), v.end(), cmp());

        bool flag = true;
        for(auto s: v){
            string tmp = "";
            for(auto c: s){
                tmp += c;

                if(hs.find(tmp) != hs.end()){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                break;
            }
            hs.insert(s);
        }
        if(flag){
            cout << "YES";
        }else{
            cout << "NO";
        }
        cout << '\n';
    }
}