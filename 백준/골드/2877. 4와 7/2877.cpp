#include <bits/stdc++.h>

using namespace std;

int arr[2] = {4, 7};
int cnt = 1;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int k;
    cin >> k;

    int sum = 0;
    while(sum < k){
        sum += pow(2, cnt);

        if(sum >= k) break;

        cnt++;
    }

    int tmp = 0;
    for(int i = 1; i < cnt; ++i){
        tmp += pow(2, i);
    }

    int num = k - tmp - 1;

    string s = "";
    for(int i = 0; i < cnt; ++i){
        s += '4';
    }

    for(int i = cnt - 1; i >= 0; --i){
        if(num % 2 != 0) s[i] = '7';

        num /= 2;
    }

    cout << s;
}