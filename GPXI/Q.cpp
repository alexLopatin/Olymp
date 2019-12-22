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
        int n;
        cin >> n;
        vector<int> cities;
        vector<int> dp(n);
        for(int i = 0; i < n; i++) {
            int val;
            cin >> val;
            cities.push_back(val);
        }
        dp[0] = cities[0];
        dp[1] = max(cities[0], cities[1]);
        for(int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2] + cities[i], dp[i - 1]);
        }
        cout << dp[n - 1] << endl;
    }
}