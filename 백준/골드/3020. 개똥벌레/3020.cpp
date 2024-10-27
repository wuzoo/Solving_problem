#include <bits/stdc++.h>
#define INF 200001;

using namespace std;

int n, h;
int top[500001]; 
int bottom[500001];

int mn = INF;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> h;

    for(int i = 1; i <= n; ++i){
        int num;
        cin >> num;

        if(i % 2 != 0){
            bottom[num]++;
        }else{
            top[h - num + 1]++;
        }
    }

    for(int i = 1; i <= h; ++i){
        bottom[h - i] += bottom[h - i + 1];
        top[i] += top[i - 1];
    }

    int cnt = 0;
    for(int i = 1; i <= h; ++i){
        if(top[i] + bottom[i] < mn){
            mn = top[i] + bottom[i];
            cnt = 1;
        }else if(top[i] + bottom[i] == mn){
            cnt++;
        }
   }

   cout << mn << ' ' << cnt;
}