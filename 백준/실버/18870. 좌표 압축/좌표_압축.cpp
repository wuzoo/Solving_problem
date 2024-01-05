#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];
vector<int> v;
pair<int, int> tmp[1000000];
int result[1000000];
int n;

bool cmp(pair<int, int> a , pair<int, int> b){
    return a.first < b.first;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        v.push_back(arr[i]);
        tmp[i] = {arr[i], i};
    }

    // sort(tmp, tmp + n, cmp);

    // int cnt = 0;
    // for(int i = 0; i < n; ++i){
    //     if(i != 0){
    //         if(tmp[i].first == tmp[i - 1].first){
    //             result[tmp[i].second] = result[tmp[i - 1].second];
    //             cnt++;
    //         }
    //         else{
    //             result[tmp[i].second] = i - cnt;
    //         }
    //     }
    //     else{
    //         result[tmp[i].second] = i;
    //     }
    // }

    // for(int i = 0; i < n; ++i){
    //     cout << result[i] << ' '; 
    // }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i = 0; i < n; ++i){
        int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
        cout << idx << ' ';
    }
}