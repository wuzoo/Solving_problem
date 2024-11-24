#include <bits/stdc++.h>

using namespace std;

double arr[100001];
double sum[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    sort(arr, arr + n + 1);

    for(int i = 1; i <= n; ++i){
        sum[i] = sum[i - 1] + arr[i];
    }

    double cutAver = ( (sum[n - k] - sum[k]) / (n - 2 * k) );

    for(int i = 1; i <= k; ++i){
        arr[i] = arr[k + 1];
        arr[n - i + 1] = arr[n - k];
    }

    double corSum = 0;
    for(int i = 1; i <= n; ++i){
        corSum += arr[i];
    }

    double corAver = corSum / n;

    cout.precision(2);
    cout << fixed;
    cout << cutAver + 1e-13 << '\n' << corAver + 1e-13;
}