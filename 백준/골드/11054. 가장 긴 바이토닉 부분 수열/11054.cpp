#include <bits/stdc++.h>

using namespace std;

int updp[1001];
int downdp[1001];
int arr[1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }   

    for(int i = 0; i < n; ++i){
        updp[i] = 1;
        for(int j = 0; j < i; ++j){
            if(arr[i] > arr[j]){
                updp[i] = max(updp[j] + 1, updp[i]);
            }
        }
    }
    for(int i = n - 1; i >= 0; --i){
        downdp[i] = 1;
        for(int j = n - 1; j > i; --j){
            if(arr[i] > arr[j]){
                downdp[i] = max(downdp[j] + 1, downdp[i]);
            }
        }
    }

    int mx = 0;
    for(int i = 0; i < n; ++i){
        mx = max(mx, updp[i] + downdp[i] - 1);
    }

    cout << mx;
}