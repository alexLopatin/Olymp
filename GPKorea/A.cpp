
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    int res = 0;
    int n;
    int m;
    cin >> n >> m;
    int carry = n % 2;
    int nBound = n / 2 + carry;
    int mBound = m / 2;
    vector<vector<int> > matrix(n);
    for (int i = 0; i < n; i++)
        matrix[i].resize(m);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            matrix[i][j] = s[j] - '0';
        }
    }
    if (m % 2 == 1 && carry == 1) {
        if (matrix[nBound - 1][mBound + m % 2 - 1] != 8) {
            res = -1;
            cout << res << endl;
            return 0;
        }
    }
    for (int i = 0; i < nBound; i++) {
        for (int j = 0; j < m; j++) {
            if (carry != 0 && i == nBound - 1 && j >= mBound) {
                break;
            }
            int a = matrix[i][j];
            int b = matrix[n - i - 1][m - j - 1];
            if (a * b == 64 || a * b == 54) {
                continue;
            }
            if (a * b == 81 || a * b == 36) {
                res++;
            }
            else if (a * b == 49) {
                res++;
            }
            else {
                res = -1;
                cout << res << endl;
                return 0;
            }
        }
    }
    cout << res << endl;
}