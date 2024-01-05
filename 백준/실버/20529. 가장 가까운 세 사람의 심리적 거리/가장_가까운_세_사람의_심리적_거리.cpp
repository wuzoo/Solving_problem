#include <iostream>
#include <cmath>
#include <algorithm>
#define INF 0xfffffff
using namespace std;

string arr[100000];

int cmp(string a, string b, string c){
    int sum = 0;
    for(int i = 0; i < 4; ++i){
        if(a[i] != b[i]){
            sum++;
        }
        if(b[i] != c[i]){
            sum++;
        }
        if(a[i] != c[i]){
            sum++;
        }
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        int tmp = INF;
        for(int i = 0; i < n - 2; ++i){
            for(int j = i + 1; j < n - 1; ++j){
                for(int k = j + 1; k < n; ++k){
                    tmp = min(tmp, cmp(arr[i], arr[j], arr[k]));
                }
                if(tmp == 0) break;
            }
            if(tmp == 0) break;
        }
        
        cout << tmp << '\n';
    }
}