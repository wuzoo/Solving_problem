#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int n, m;

int binary_search(int num){
    int st = 0;
    int en = n - 1;
    while(st <= en){
        int mid = (st + en) / 2;
        if(arr[mid] > num){
            en = mid - 1;
        }
        else if(arr[mid] < num){
            st = mid + 1;
        }
        else{
            return 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    cin >> m;
    sort(arr, arr + n);
    for(int i = 0; i < m; ++i){
        int num;
        cin >> num;
        cout << binary_search(num) << " ";
    }

    return 0;
}