#include <iostream>
using namespace std;

void hanoi_cnt(int n){
    int num = 1;
    while(--n){
        num = num * 2 + 1;
    }

    cout << num << '\n';
}

void hanoi(int from, int via, int to, int n){
    if(n == 1){
        cout << from << ' ' << to << '\n';
    }
    else{
        hanoi(from, to, via, n - 1);
        cout << from << ' ' << to << '\n';
        hanoi(via, from, to, n - 1);
    }
}

int main(){
    int n;
    cin >> n;

    hanoi_cnt(n);
    hanoi(1, 2, 3, n);
}