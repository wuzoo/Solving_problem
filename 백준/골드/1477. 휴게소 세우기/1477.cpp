#include <bits/stdc++.h>

using namespace std;

int n, m, l;
vector<int> arr;
int ans = 1001;

bool check(int mid){
    int cnt = 0;
    int midCnt = 0;

    for(int i = 0; i < arr.size() - 1; ++i){
        int gap = arr[i + 1] - arr[i];
        cnt += gap / mid;

        if(gap % mid == 0){
            cnt--;
        }
    }

    return cnt > m;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> l;

    for(int i = 0; i < n; ++i){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    arr.push_back(0);
    arr.push_back(l);

    sort(arr.begin(), arr.end());

    int st = 1;
    int en = l + 1;

    while(st < en){
        int mid = (st + en) / 2; 

        if(check(mid)){
            st = mid + 1;
        }else{
            ans = mid;
            en = mid;
        }
    } 

    cout << ans;
}