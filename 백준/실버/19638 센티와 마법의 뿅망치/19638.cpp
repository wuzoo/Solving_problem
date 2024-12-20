#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, h, t; cin >> n >> h >> t;

    priority_queue<int> q;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        q.push(arr[i]);
    }

    int cnt = 0;
    while(t-- && q.top() >= h){
        int highest = q.top();
        if(highest == 1) break;
        q.pop();

        q.push(highest / 2);
        cnt++;
    }

    if(q.top() >= h) cout << "NO" << '\n' << q.top();
    else cout << "YES" << '\n' << cnt;
}