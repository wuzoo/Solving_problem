#include <bits/stdc++.h>

using namespace std;

int t, n, m;
int a[1001], b[1001];
long long ans;
vector<int> sumA, sumB;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> t;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> b[i];
    }

    for(int i = 0; i < n; ++i){
        int sum = a[i];
        sumA.push_back(sum);

        for(int j = i + 1; j < n; ++j){
            sum += a[j];
            sumA.push_back(sum);
        }
    }
    sort(sumA.begin(), sumA.end());

    for(int i = 0; i < m; ++i){
        int sum = b[i];
        sumB.push_back(sum);

        for(int j = i + 1; j < m; ++j){
            sum += b[j];
            sumB.push_back(sum);
        }
    }
    sort(sumB.begin(), sumB.end());


    for(int i = 0; i < sumA.size(); ++i){
        int target_value = t - sumA[i];

        int low = lower_bound(sumB.begin(), sumB.end(), target_value) - sumB.begin();
        int high = upper_bound(sumB.begin(), sumB.end(), target_value) - sumB.begin();

        ans += high - low;
    }

    cout << ans;
}