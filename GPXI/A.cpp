#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n, m;
    cin >> n >> m;
    long long res = 0;
    long long xRes = 0;
    for(int i = 0; i < n; i++) {
        int xL = min(i, n - i);
        xRes += xL;
    }
    res += xRes * (m + 1);
    long long yRes = 0;
    for(int i = 0; i < m; i++) {
        int yL = min(i, m - i);
        yRes += yL;
    }
    res += yRes * (n + 1);
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            int xL = min(i, n - i);
            int yL = min(j, m - j);
            res += xL*yL * 2;
        }
    }
    cout << res << endl;
}