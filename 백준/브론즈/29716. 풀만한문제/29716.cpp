#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int j, n;
    cin >> j >> n;
    cin.ignore();

    int cnt = 0;
    for(int i = 0; i < n; ++i){
        string s;
        getline(cin, s);

        int length = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] >= 65 && s[i] <= 90){
                length += 4;
            }
            else if(s[i] >= 97 && s[i] <= 122){
                length += 2;
            }else if(s[i] >= 48 && s[i] <= 57){
                length += 2;
            }else if(s[i] == ' '){  
                length += 1;
            }
        }

        if(length <= j){
            cnt++;
        }
    }

    cout << cnt << '\n';
}