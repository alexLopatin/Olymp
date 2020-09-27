#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

#define ll long long

vector<double> x;
vector<double> y;
int n;

double F(double k, double b)
{
	double res = 0;

	for (int i = 0; i < n; i++)
	{
		res += abs(x[i] - (k * y[i] + b));
	}

	return res;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		double v;
		cin >> v;
		x.push_back(v);
	}

	for (int i = 0; i < n; i++)
	{
		double v;
		cin >> v;
		y.push_back(v);
	}

	double min = 1000.0 * 300.0 * 1000.0;

	double kMin = 0;
	double bMin = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double k = (x[i] - x[j]) / (y[i] - y[j]);
			double b = x[j] - k * y[j];
			double f = F(k, b);

			if (min > f)
			{
				min = f;
				kMin = k;
				bMin = b;
			}
		}
	}


	cout << setprecision(20) << min << ' ' << setprecision(20) << kMin << ' ' << setprecision(20) << bMin << endl;
}