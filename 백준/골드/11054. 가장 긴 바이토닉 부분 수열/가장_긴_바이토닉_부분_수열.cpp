#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];
int up[1000];
int down[1000];
int dp[1000];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    for(int i = 0; i < n; ++i){
        up[i] = 1;
        down[i] = 1;
        for(int j = 0; j < i; ++j){
            if(arr[i] > arr[j]){
                up[i] = max(up[i], up[j] + 1);
            }
            else if(arr[i] < arr[j]){
                down[i] = max(down[j] + 1, down[i]);
                down[i] = max(down[i], up[j] + 1);
            }
        }
        dp[i] = max(up[i], down[i]);
    }
    int mx = 0;
    for(int i = 0; i < n; ++i){
        mx = max(mx, dp[i]);
    }
    cout << mx;
}