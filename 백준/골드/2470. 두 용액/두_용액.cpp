#include <iostream>
#include <cmath>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;

int ans = INF;
int arr[100001];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int result[2] = {};
    int left = 0;
    int right = n - 1;
    while(left < right){
        int sum = arr[left] + arr[right];
        
        if(abs(sum) < ans){
            result[0] = arr[left];
            result[1] = arr[right];
            ans = abs(sum);

            if(sum == 0) break;
        }
        if(sum < 0){
            left++;
        }
        else{
            right--;
        }
    }

    cout << result[0] << ' ' << result[1];
}