#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int l, r;
    cin >> l >> r;

    string sl = to_string(l);
    string sr = to_string(r);

    int eightCnt = 0;
    if(sl.length() == sr.length()){
        for(int i = 0; i < sr.length(); ++i){
            if(sl[i] == sr[i]){
                if(sl[i] == '8'){
                    eightCnt++;
                }
            }else{
                break;
            }
        }
        cout << eightCnt;
    }else{
        cout << 0;
    }
}