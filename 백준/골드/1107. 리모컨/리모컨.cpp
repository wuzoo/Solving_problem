#include <iostream>
#include <string>
#include <cmath>
#define INF 0x7fffffff
using namespace std;

char button[11];
int channels[1000002];

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        cin >> button[i];
    }

    for(int i = 0; i < 1000001; ++i){
        channels[i] = 1;
        string n = to_string(i);
        for(int j = 0; j < m; ++j){
            if(n.find(button[j]) != string::npos){
                channels[i] = 0; // 채널 못만든다.
                break;
            }
        }
    }
    channels[100] = 1;

    int result = INF;
    for(int i = n; i < n + abs(n - 100); ++i){
        if(channels[i]){
            result = to_string(i).length() + abs(i - n);
            break;
        }
    }
    int result2 = INF;
    for(int i = n; i >= 0; --i){
        if(channels[i]){
            result2 = to_string(i).length() + abs(i - n);
            break;
        }
    }
    int third = abs(n - 100);

    if(result >= result2){
        if(result2 > third){
            cout << third;
        }
        else{
            cout << result2;
        }
    }
    else{
        if(result > third){
            cout << third;
        }
        else{
            cout << result;
        }
    }
}