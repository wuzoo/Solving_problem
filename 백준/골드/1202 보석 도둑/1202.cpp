#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vector<pair<int, int>> arr;   
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        int m, v;
        cin >> m >> v;

        arr.push_back({m, v});
    }
    
    vector<int> bags;
    for(int i = 0; i < k; ++i){
        int bag;
        cin >> bag;
        bags.push_back(bag);
    }

    priority_queue<int> q;

    sort(arr.begin(), arr.end());
    sort(bags.begin(), bags.end());

    int index = 0;
    long sum = 0;
    for(int i = 0; i < bags.size(); ++i){
        int capacity = bags[i];

        while(index < n && arr[index].first <= capacity){
            q.push(arr[index].second);
            index++;
        }

        if(!q.empty()){
            sum += q.top();
            q.pop();
        }
    }

    cout << sum;
}