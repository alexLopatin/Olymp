
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    vector<double> x;
    vector<double> y;
    for(int i = 0; i < n; i++) {
    	double xt, yt;
    	cin >> xt >> yt;
    	x.push_back(xt);
    	y.push_back(yt);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
    	int p;
    	cin >> p;
    	double distance = 0;
    	int prevIndex = 0;
    	cin >> prevIndex;
    	for(int j = 0; j < p - 1; j++) {
    		int curIndex;
    		cin >> curIndex;
    		distance += sqrt((x[curIndex] - x[prevIndex])*(x[curIndex] - x[prevIndex]) + (y[curIndex] - y[prevIndex])*(y[curIndex] - y[prevIndex]));
    		prevIndex = curIndex;
    	}
    	cout << round(distance) << endl;
    }
}