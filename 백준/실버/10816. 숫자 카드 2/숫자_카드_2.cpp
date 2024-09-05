#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[500000];
int cnt[500000];

int lower_idx(int num){
    int st = 0;
    int en = n;
    while(st < en){
        int mid = (st + en) / 2;
        if(arr[mid] >= num) en = mid;
        else{
            st = mid + 1;
        }
    }
    return st;
}

int upper_idx(int num){
    int st = 0;
    int en = n;
    while(st < en){
        int mid = (st + en) / 2;
        if(arr[mid] > num) en = mid;
        else{
            st = mid + 1;
        }
    }
    return st;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cin >> m;
    for(int i = 0; i < m; ++i){
        int num;
        cin >> num;
        cout << upper_idx(num) - lower_idx(num) << ' ';
    }
}