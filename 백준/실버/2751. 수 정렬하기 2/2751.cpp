#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        pq.push(x);
    }

    while(!pq.empty()){
        cout << pq.top() << '\n';
        pq.pop();
    }
}