#include <iostream>
using namespace std;

// 0 1 1 2 3 5 8 ..
int fibonachi(int num){
    if(num == 0){
        return 0;
    }
    if(num == 1){
        return 1;
    }
    return fibonachi(num - 1) + fibonachi(num - 2);
}

int main(){
    int n;
    cin >> n;

    cout << fibonachi(n);
}