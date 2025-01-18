#include <bits/stdc++.h>

using namespace std;

int n;
int arr[101];

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

   
    vector<int> gap;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(i == j) continue;

            gap.push_back(abs(arr[i] - arr[j]));
        }
    }
    
    sort(gap.begin(), gap.end());

    vector<int> result;

    int g = gap[0];
    for(int i = 1; i < gap.size() - 1; ++i){
        g = gcd(g, gap[i]);
    }

    for(int i = 2; i <= g; ++i){
        if(g % i == 0) result.push_back(i);
    }

    for(auto s: result){
        cout << s << ' ';
    }
}