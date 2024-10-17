#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    set<string> s;

    int n;
    cin >> n;

    int sum = 0;
    for(int i = 0; i < n; ++i){
        string str;
        cin >> str;

        if(str == "ENTER"){
            sum += s.size();
            s.clear();

            continue;
        };
        
        s.insert(str);
    }

    if(s.size()) sum += s.size();

    cout << sum;
}