#include <iostream>
using namespace std;

int arr[1000001];

int main(){
    int m, n;
    cin >> m >> n;

    arr[1] = -1;
    for(int i = 2; i <= n; ++i){

        if(arr[i] == -1) continue;

        for(int j = i + i; j <= n; j += i){
            arr[j] = -1;
        }
    }

    for(int i = m; i <= n; ++i){
        if(arr[i] == 0){
            cout << i << '\n';
        }
    }
}