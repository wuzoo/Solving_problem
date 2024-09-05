#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 0x7fffffff
using namespace std;

int graph[101][101];
int n,m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
        graph[y][x] = 1;
	}
    
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j) continue; 
					
				if(graph[i][k] != 0 && graph[k][j] != 0){
					if(graph[i][j] == 0){
						graph[i][j] = graph[i][k] + graph[k][j];
					}else{ 
						graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]); 
					}
				}
			}
		}
	}

    int mn = INF; int idx = 0;
    for(int i = 1; i <= n; ++i){
        int sum = 0;
        for(int j = 1; j <=n; ++j){
            sum += graph[i][j];
        }
        if(mn > sum){
            idx = i;
            mn = sum;
        }
    }
    cout << idx;
}