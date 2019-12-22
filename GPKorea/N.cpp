
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    int powers[3] = {1, 10, 100};
    int n;
    cin >> n;   
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int sum = 0;
        int c = 0;
        int k = 0;
        int sign = 1;
        bool b = true;
        for ( int j = s.length() - 1; j >= 0; j--) {
            if(s[j] == '-') {
                continue;
            }
            int cur = s[j] - '0';
            if(cur == 7) {
                cout << 1 << endl;
                b = 0;
                break;
            }
            c += powers[k] * cur;
            k++;
            k = k % 3;
            if( k == 0) {
                sum += sign * c;
                sign *= -1;
                c = 0;
            }
        }
        if(b) {
            sum += sign * c;
            if( sum % 7 == 0) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }
}