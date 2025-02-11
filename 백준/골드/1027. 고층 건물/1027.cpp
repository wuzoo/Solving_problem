#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;

    vector<double> arr;
    for(int i = 0; i < n; ++i){
        double num; cin >> num;
        arr.push_back(num);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        int cnt = 0;
        for(int j = 0; j < n; ++j){
            bool canSee = true;

            if(i == j) continue;
            
            if(abs(i - j) == 1){
                cnt++;
                continue;
            }

            double unit = (double)((arr[i] - arr[j]) / (double)(i - j));

            int minIdx = i > j ? j : i;
            int maxIdx = i > j ? i : j;

            for(int k = minIdx + 1; k < maxIdx; ++k){
                if(arr[k] >= arr[minIdx] + unit * double(k - minIdx)){
                    canSee = false;
                    break;
                }
            }
            
            if(canSee){
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans;
}