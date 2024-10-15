#include <bits/stdc++.h>

using namespace std;

int arr[10][10];
bool isEnd;

vector<pair<int, int>> v;

bool check(int x, int y, int k){
    for(int i = 1; i <= 9; ++i){
            if(arr[x][i] == k && y != i) return false;

            if(arr[i][y] == k && x != i) return false;

            int nx = (x - 1) / 3 * 3 + 1 + (i - 1) / 3;
            int ny = (y - 1) / 3 * 3 + 1 + (i - 1) % 3;
            if(arr[nx][ny] == k && !(nx == x && ny == y)) return false;
    }
    return true;
}

void DFS(int idx){
    if(isEnd) return;

    if(idx == v.size()){
        isEnd = true;
        for(int i = 1; i <= 9; ++i){
            for(int j = 1; j <= 9; ++j){
                cout << arr[i][j];
            }
            cout << '\n';
        }
        return;
    }

    int x = v[idx].first;
    int y = v[idx].second;

    for(int i = 1; i <= 9; ++i){
        if(check(x, y, i)){
            arr[x][y] = i;
            DFS(idx + 1);
            arr[x][y] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    for(int i = 1; i <= 9; ++i){
        for(int j = 1; j <= 9; ++j){
            char c;
            cin >> c;
            arr[i][j] = c - '0';
            
            if(arr[i][j] == 0){
                v.push_back({i, j});
            }
        }
    }

    DFS(0);
}