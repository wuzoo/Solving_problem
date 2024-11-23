#include <bits/stdc++.h>

using namespace std;

int arr[1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vector<int> v;
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            v.push_back(arr[i] + arr[j]);
        }
    }

    sort(arr, arr + n);
    sort(v.begin(), v.end());
    
    for(int i = n - 1; i >= 0; --i){
        for(int j = i; j >= 0; --j){
            int t = arr[i] - arr[j];

            bool ok = binary_search(v.begin(), v.end(), t);

            if(ok){
                cout << arr[i];
                return 0;
            }
        }
    }
}