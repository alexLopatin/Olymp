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
        vector<int> x;
        vector<int> y;
        for(int i = 0; i < n; i++){
            int xs, ys;
            cin >> xs >> ys;
            x.push_back(xs);
            y.push_back(ys);
        }
        int det = (x[1]-x[0])*(y[2]-y[0]) - (x[2]-x[0])*(y[1]-y[0]);
        if(det > 0)
            cout << "LEFT\n";
        else
            cout << "RIGHT\n";
    }
}