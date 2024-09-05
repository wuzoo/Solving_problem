#include <iostream>
#include <cstring>
using namespace std;

int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b, a % b);
}
long long lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        int x, y;
        cin >> x >> y;

        long long mx = lcm(m, n);
        long long num = -1;
        for(int i = x; i <= mx; i += m){
            int nn = i % n;
            if(nn == 0){
                nn = n;
            }
            if(nn == y){
                num = i;
                break;
            }
        }
        cout << num << '\n';
    }
}