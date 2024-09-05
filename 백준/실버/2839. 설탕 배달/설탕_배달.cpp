#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int fivecnt = 0;
    if(n < 5){
        if(n % 3 == 0){
            cout << n / 3;
        }
        else{
            cout << -1;
        }
        return 0;
    }
    while(n >= 5){
        n -= 5;
        fivecnt++;
    }

    if(n == 0){
        cout << fivecnt;
    }
    else{
        if(n == 3) cout << fivecnt + 1;
        else{ // 남은 설탕무게가 3으로 계산 안될때.
            bool canmake = false;
            while(fivecnt > 0){
                n += 5;
                fivecnt--;

                if(n % 3 == 0){
                    cout << fivecnt + n / 3;
                    canmake = true;
                    break;
                }
            }
            if(!canmake) cout << -1;
        }
    }
}