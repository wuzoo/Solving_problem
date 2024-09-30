#include <bits/stdc++.h>

using namespace std;

int arr[2001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        int target = arr[i];
        int st = 0;
        int en = n - 1;

        while(st < en) {
            if(st == i) {
                st++;
                continue;
            };
            if(en == i){
                en--;
                continue;
            }
            if(arr[st] + arr[en] == target) {
                cnt++;
                break;
            }
            if(arr[st] + arr[en] < target) {
                st++;
            }
            else {
                en--;
            }
        }
    }

    cout << cnt << '\n';
}