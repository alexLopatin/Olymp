#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
    int N;
    while(cin >> N) {
        if(N == 1)
            return 0;

        vector<int> a;
        for(int i = 0; i < N; i++) {
            int v;
            cin >> v;
            a.push_back(v);
        }
        int res = 0;
        int val = 2000000;
        multiset<int> left;
        multiset<int> right;
        for(int i = 0; i < N; i++) {
            right.insert(a[i]);
        }
        for(int i = 0; i < N - 1; i++) {
            left.insert(a[i]);
            right.erase(right.lower_bound(a[i]));
            int curVal = max( *right.rbegin() - *right.begin(), *left.rbegin() - *left.begin());
            if(curVal < val) {
                res = i;
                val = curVal;
            }
        }
        cout << res + 1 << endl;
    }
}