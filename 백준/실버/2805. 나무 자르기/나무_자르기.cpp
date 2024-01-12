#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1000000];
long long n, m;

long long getTree(int len){
    long long sum = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] > len) sum += (arr[i] - len);
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    long long st = 0;
    long long en = arr[n - 1];
    long long max = 0;

    while(st <= en){
        long long mid = (st + en) / 2;
        if(getTree(mid) < m){
            en = mid - 1;
        }
        // m과 자른 나무의 길이가 같아도, 절단기의 높이를 1 더 높혔을때도 자른 나무의 길이가 같을 수 있으니 계속 높혀봐야함.
        // 따라서 같다고 중단하는 것이 아닌 계속 탐색
        else if(getTree(mid) >= m){
            max = mid;
            st = mid + 1;
        }
    }
    cout << max;
}