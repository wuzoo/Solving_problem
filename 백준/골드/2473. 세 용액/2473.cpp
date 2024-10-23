#include <bits/stdc++.h>

using namespace std;

vector<long long> arr;
long long mn = 3000000001;
tuple<long long, long long, long long> ans;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        long long num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n - 2; ++i){
        int current = i;
        int st = i + 1;
        int en = n - 1;
        while(st < en){
            long long value = arr[st] + arr[current] + arr[en];

            if(mn > abs(value)){
                mn = abs(value);
                ans = {arr[current], arr[st], arr[en]};
            }
            if(value < 0){
                st++;
            }
            else{
                en--;
            }
        }
    }
    
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' <<  get<2>(ans);
}