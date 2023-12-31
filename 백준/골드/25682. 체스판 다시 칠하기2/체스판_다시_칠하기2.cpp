#include <iostream>
using namespace std;

int n, m, k;
int grid[2001][2001];
int psum[2001][2001];
int ret = 100000000;

int chess(int color){ // 첫 번째 시작 컬러
    int value = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(!((i + j) % 2 == 0)){
                value = grid[i][j] != color;
            }
            else{
                value = grid[i][j] == color;
            }
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + value;
        }
    }

    for(int i = 1; i <= n - k + 1; ++i){
        for(int j = 1; j <= m - k + 1; ++j){
            ret = min(ret, psum[i + k - 1][j + k - 1] - psum[i - 1][j + k - 1] - psum[i + k - 1][j - 1] + psum[i - 1][j - 1]);
        }
    }
    return ret;
}

int main(){
    cin >> n >> m >> k;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            char c;
            cin >> c;
            grid[i][j] = (c == 'B'); // black이면 1
        }
    }

    cout << min(chess(1), chess(0));
}