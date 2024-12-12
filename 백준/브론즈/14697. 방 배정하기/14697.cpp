#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int a, b, c, n;
    cin >> a >> b >> c >> n;

    int maxA = n / a;
    int maxB = n / b;
    int maxC = n / c;

    bool success = false;
    for(int i = 0; i <= maxA; ++i){
        for(int j = 0; j <= maxB; ++j){
            for(int k = 0; k <= maxC; ++k){
                if(a * i + b * j + c * k == n){
                    success = true;
                    break;
                }
            }
        }
    }

    if(success) cout << 1;
    else cout << 0;
}