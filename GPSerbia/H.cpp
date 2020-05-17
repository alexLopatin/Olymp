#include <iostream>
#include <math.h>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> x, y;
	for (int i = 0; i < n; i++)
	{
		int xp, yp;
		cin >> xp >> yp;
		x.push_back(xp);
		y.push_back(yp);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	long long sumX = 0, sumY = 0;
	for (int i = 0; i < n; i++)
	{
		sumX += abs(i + 1 - x[i]);
		sumY += abs(i + 1 - y[i]);
	}
	cout << sumX + sumY << endl;

}