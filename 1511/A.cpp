#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	string a, b;
	cin >> a >> b;
	vector<vector<int>> lcs(a.length() + 1);
	for(int i = 0; i <= a.length(); i++)
		lcs[i].resize(b.length() + 1);
	
	for(int i = 0; i <= a.length(); i++)
		for(int j = 0; j <= b.length(); j++) {
			if(i ==0 || j == 0)
				lcs[i][j] = 0;
			else if(a[i - 1] == b[j - 1]) {
				lcs[i][j] = lcs[i-1][j-1] + 1;
			} 
			else {
				lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
			}
		}
	cout << lcs[a.length()][b.length()] << endl;
}
