#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> p;
vector<vector<int>> m;

int MCM(int l, int r) {
	if(m[l][r] == -1) {
		if( l == r - 1) {
			m[l][r] = 0;
		}
		else {
			m[l][r] = 1000000007;
			for(int i = l + 1; i<= r - 1; i++) {
				m[l][r] = min(m[l][r], p[l] * p[i] * p[r] +  MCM(l, i) + MCM(i, r));
			}
		}
	}
	return m[l][r];
}

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	p.resize(n + 1);
	m.resize(n + 1);
	for(int i = 0; i <= n; i++)
		m[i].resize(n + 1);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			m[i][j] = -1;

	for(int i = 0; i < n; i++) {
		int p1, p2;
		cin >> p1 >> p2;
		p[i] = p1;
		if(i == n - 1){
			p[n] = p2;
		}
	}
	
	cout << MCM(1, n) << endl;
}
