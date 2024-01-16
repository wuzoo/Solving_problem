#include <iostream>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;

char map[51][51];
int n, m;

int check(char color){
    // 첫번째 원소가 흰색이면 (x + y) % 2 != 0 이면 블랙, 0이면 흰색 (시작 지점 : 1, 1) 
    int mn = INF;
    int cnt = 0;
    for(int x = 1; x <= n - 7; ++x){
        for(int y = 1; y <= m - 7; ++y){
            for(int i = x; i < x + 8; ++i){
                for(int j = y; j < y + 8; ++j){
                    if((i + j) % 2 == 0){
                        if(map[i][j] != color){
                            cnt++;
                        }
                    }
                    else{
                        if(map[i][j] == color){
                            cnt++;
                        }
                    }
                    
                }
            }
            mn = min(mn, cnt);
            cnt = 0;
        }
    }
    return mn;
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            char c;
            cin >> c;
            map[i][j] = c;
        }
    }

    cout << min(check('W'),check('B'));
}