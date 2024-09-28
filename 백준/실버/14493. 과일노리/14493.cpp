#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    int time = 0;
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;

        int mod = time % (a + b);

        if(mod < b) time += b - mod;

        time++;
    }

    cout << time;
}