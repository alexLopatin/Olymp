#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
    int T;
    cin >> T;
    for(int k = 0; k < T; k++) {
        long long res = 0;
        int n, m;
        cin >> n >> m;
        vector<vector < int > > grid(n);
        for(int i = 0; i < n; i++)
            grid[i].resize(m);

        int startX = 0;
        int startY = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char c;
                cin >> c;
                if(c == 'S') {
                    startX = i;
                    startY = j;
                }
                grid[i][j] = c;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'B') {
                    res += abs(i - startX) + abs(j - startY);   
                }
            }
        }
        
        cout << res * 2 << endl;
    }
}