#include <bits/stdc++.h>

using namespace std;

int canWin(char a, char b){
    if(a == 'R'){
        if(b == 'S') return 1;
        else if(b == 'P') return -1;
    }else if(a == 'P'){
        if(b == 'R') return 1;
        else if(b == 'S') return -1;
    }else if(a == 'S'){
        if(b == 'P') return 1;
        else if(b == 'R') return -1;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    char min[2];
    char tae[2];
    for(int i = 0; i < 2; ++i){
        cin >> min[i];
    }
    for(int i = 0; i < 2; ++i){
        cin >> tae[i];
    }

    if((canWin(min[0], tae[0]) == 1 && canWin(min[0], tae[1]) == 1) || canWin(min[1], tae[0]) == 1 && canWin(min[1], tae[1]) == 1){
            cout << "MS";
    }
    else if((canWin(tae[0], min[0]) == 1 && canWin(tae[0], min[1]) == 1) || canWin(tae[1], min[0]) == 1 && canWin(tae[1], min[1]) == 1){
            cout << "TK";
    }else{
        cout << '?';
    }
}