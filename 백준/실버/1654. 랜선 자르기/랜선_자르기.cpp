#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
long long arr[10000];

// 만들어진 랜선 개수
long long getLength(long long len){
    long long sum = 0;
    for(int i = 0; i < k; ++i){
        sum += arr[i] / len;
    }
    return sum;
}

int main(){
    cin >> k >> n;

    for(int i = 0; i < k; ++i){
        cin >> arr[i];
    }
    
    sort(arr, arr + k);

    long long st = 1;
    long long en = arr[k - 1];

    long long ans = 0;
    while(st <= en){
        long long mid = (st + en) / 2;
        long long cnt = getLength(mid);
        if(cnt < n){
            en = mid - 1;
        }
        else{
            ans = max(ans, mid);
            st = mid + 1;
        }
    }

    cout << ans;
}