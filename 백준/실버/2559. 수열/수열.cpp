#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100001], ksum[100001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        ksum[i] = ksum[i - 1] + arr[i];
    }

    vector<int> sum;
    for(int i = k; i <= n; ++i){
        sum.push_back(ksum[i] - ksum[i - k]);
    }

    int mx = -10000001;
    for(int i = 0; i < sum.size(); ++i){
        if(mx < sum[i]){
            mx = sum[i];
        }
    }
    cout << mx;
    return 0;
}