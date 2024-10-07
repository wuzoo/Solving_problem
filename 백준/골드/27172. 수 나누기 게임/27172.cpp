#include <bits/stdc++.h>

using namespace std;

int arr[1000001];
int card[1000001];
int result[1000001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        card[arr[i]] = 1;
    }

    for(int i = 0; i < n; ++i){
        for(int j = arr[i] * 2; j <= 1000000; j += arr[i]){
            if(card[j]){
                result[arr[i]]++;
                result[j]--;
            }
        }
    }

    for(int i = 0; i < n; ++i){
        cout << result[arr[i]] << ' ';
    }
}