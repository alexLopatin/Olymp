#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct troiki{
    double a;
    double b;
    double c;
};

bool f(troiki a, troiki b) {
    
}

int main(int argc, char *argv[]) {
    int n, k;
    int long long S, P;
    cin >> n >> k >> S >> P;
    vector<vector<double>> matches(n);
    for( int i = 0; i < n; i++) {
        double a, b, c;
        cin >> a >> b >> c;
        matches[i].push_back(a);
        matches[i].push_back(b);
        matches[i].push_back(c);
        sort(matches[i].begin(), matches[i].end());
    }
    for( int i = 0; i < k; i++) {
        int doubles, triples;
        long long price;
        cin >> doubles >> triples >> price;

    }
    
}