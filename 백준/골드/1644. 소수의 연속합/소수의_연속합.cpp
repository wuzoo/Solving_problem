#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n;
int arr[4000001];
vector<int> prime;

int main(){
    cin >> n;
    for(int i = 2; i <= n; ++i){
        arr[i] = i;
    }

    for(int i = 2; i <= n; ++i){
        if(arr[i] == 0) continue;

        for(int j = i + i; j <= n; j += i){
            arr[j] = 0;
        }
    }

    for(int i = 2; i <= n; ++i){
        if(arr[i] != 0) prime.push_back(arr[i]);
    }

    int en = 0; int cnt = 0;
    if(n == 1){
        cout << 0;
        return 0;
    }
    int sum = prime[0];
    for(int st = 0; st < prime.size(); ++st){
        while(sum < n && en < prime.size()){
            en++;
            if(en != prime.size()) sum += prime[en];
        }
        if(en == prime.size()) break;
        if(sum == n){
            cnt++;
        }
        sum -= prime[st];
    }
    cout << cnt;
}