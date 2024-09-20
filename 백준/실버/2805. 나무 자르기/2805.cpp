#include <bits/stdc++.h>
using namespace std;

int n, m;
long long arr[1000001];
long long max_h;

long long getTree(long long h){
    long long sum = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] > h) sum += arr[i] - h; 
    }
    return sum;
}

void binarysearch(int start, int end){
    long long st = start;
    long long en = end;
    while(st <= en){
        long long mid = (st + en) / 2;
        
        long long res = getTree(mid); // 잘린 나무 합

        if(res >= m){
            st = mid + 1;
            max_h = mid;
        }else if(res < m){
            en = mid - 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    binarysearch(0, arr[n - 1]);

    cout << max_h;
}