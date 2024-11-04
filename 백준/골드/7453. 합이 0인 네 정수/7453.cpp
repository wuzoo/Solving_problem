#include <bits/stdc++.h>

using namespace std;

long long ans;
int arr[4][4001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 4; ++j){
            cin >> arr[j][i];
        }
    }

    vector<int> ab;
    vector<int> cd;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            ab.push_back(arr[0][i] + arr[1][j]);
            cd.push_back(arr[2][i] + arr[3][j]);
        }
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    int st = 0;
    int en = cd.size() - 1;

    while(st < ab.size() && en >= 0){
        if(ab[st] + cd[en] == 0){
            int first = st;

            long long cnt1 = 0;
            while(ab[st] + cd[en] == 0){
                if(st >= ab.size()) break;
                st++;
                cnt1++;
            }

            long long cnt2 = 0;
            while(ab[first] + cd[en] == 0){
                if(en < 0) break;
                en--;
                cnt2++;
            }

            ans += cnt1 * cnt2;
        }else if(ab[st] + cd[en] > 0){
            en--;
        }else{
            st++;
        }
    }

    cout << ans;
}