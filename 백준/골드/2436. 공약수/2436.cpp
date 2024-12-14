#include <bits/stdc++.h>

using namespace std;

long long hi(long long a, long long b){
    if(b == 0) return a;

    return hi(b, a % b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    long long gcd, lcm; cin >> gcd >> lcm;
    long long divide = lcm / gcd;
    long long a, b;
    pair<long long, long long> result;
    for(int i = 1; i <= sqrt(divide); i++){
        if(divide % i == 0){
            a = i;
            b = divide / i;

            if(hi(a, b) == 1){
                result = {a, b};
            }
        }
    }

    cout << result.first * gcd << ' ' << result.second * gcd;
}