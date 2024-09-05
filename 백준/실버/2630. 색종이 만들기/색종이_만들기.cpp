#include <iostream>
using namespace std;

int map[128][128];
int white; int blue;

void func(int n, int x, int y){
    if(n == 1){
        if(map[x][y] == 1) blue++;
        if(map[x][y] == 0) white++;

        return;
    }

    bool can = true;
    int first = map[x][y];
    for(int i = x; i < n + x; ++i){
        for(int j = y; j < n + y; ++j){
            if(map[i][j] != first){
                can = false;
                break;
            }
        }
        if(!can) break;
    }
    if(can){
        if(first) blue++;
        else white++;

        return;
    }
    
    func(n / 2, x, y + n / 2); func(n / 2, x + n / 2, y); func(n / 2, x, y); func(n / 2, x + n / 2, y + n / 2);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> map[i][j];
        }
    }

    func(n, 0, 0);

    cout << white << '\n' << blue;
}