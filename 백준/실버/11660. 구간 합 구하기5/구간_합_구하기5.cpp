#include <iostream>
using namespace std;

int grid[1025][1025];
long long sum[1025][1025];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> grid[j][i];
            sum[j][i] = sum[j][i - 1] + grid[j][i];
        }
    }
    for(int i = 0; i < m; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long s = 0;
        for(int j = y1; j <= y2; ++j){
            s += sum[j][x2] - sum[j][x1 - 1];
        }
        cout << s << '\n';
    }

    return 0;
}