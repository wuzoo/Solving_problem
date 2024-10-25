#include <bits/stdc++.h>

using namespace std;

int arr[1001];
int friends[1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    for(int i = 0; i < m; ++i){
        int num;
        cin >> num;
        friends[num] = 1; 
    }

    int cnt = 0;
    for(int i = 0; i < m; ++i){
        if(!friends[arr[i]]){
            cnt++;
        }
    }

    cout << cnt;
}