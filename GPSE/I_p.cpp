
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;
    for( int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    for( int i = 0; i < n; i++) {
        int t;
        cin >> t;
        b.push_back(t);
    }
    vector<int> deltas(n);
    for( int i = 0; i < n; i++) {
        int min = 1000000000;
        for( int j = 0; j < n; j++) {
            if(abs(a[i]-b[j]) < min) {
                min = abs(a[i]-b[j]);
            }
        }
        deltas[i] = min;
    }
    int max = 0;
    for( int i = 0; i < n; i++) {
        if(deltas[i] > max) {
            max = deltas[i];
        }
    }
    cout << max << endl;
}