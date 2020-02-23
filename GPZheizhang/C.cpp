#include <iostream>
#include <math.h>

using namespace std;

struct Point
{
	int x;
	int y;
};

long long x_c, y_c, x_0, y_0, r;

unsigned long long CalcSquareDistance(long long x1, long long y1, long long x2, long long y2)
{
	return (unsigned long long)(x1 - x2) * (x1 - x2) + (unsigned long long)(y1 - y2) * (y1 - y2);
}


bool IsInCircle(double x, double y)
{
	return ((x - x_c) * (x - x_c) + (y - y_c) * (y - y_c) <= r * r);
}

Point FindClosest(double x, double y)
{
	Point result;
	unsigned long long distance = 18446744073709551615ull;
	result.x = 0;
	result.y = 0;
	long long downBorder = floor(y) - 1420;
	long long upBorder = ceil(y) + 1420;
	long long leftBorder = floor(x) - 1420;
	long long rightBorder = ceil(x) + 1420;
	for (long long i = leftBorder; i <= rightBorder; i++)
	{
		for (long long j = downBorder; j <= upBorder; j++)
		{
			bool b = IsInCircle(i, j);
			if (IsInCircle(i, j) && distance > CalcSquareDistance(x_0, y_0, i, j))
			{
				distance = CalcSquareDistance(x_0, y_0, i, j);
				result.x = i;
				result.y = j;
			}
		}
	}
	return result;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> x_c >> y_c >> r >> x_0 >> y_0;
		double m = (r * r * (double)(y_0 - y_c) * (y_0 - y_c)) / ((x_0 - x_c) * (x_0 - x_c) + (y_0 - y_c) * (y_0 - y_c));
		if (IsInCircle(x_0, y_0))
			cout << "0\n" << x_0 << " " << y_0 << endl;
		else
		{
			cout << "1\n" << x_0 << " " << y_0 << " ";
			double y = sqrt(m) + y_c;
			double x = sqrt(m) * (double)(x_0 - x_c) / (double)(y_0 - y_c) + x_c;
			if (x_c == x_0)
			{
				y = r + y_c;
				x = x_c;
			}
			if (y_c == y_0)
			{
				y = y_c;
				x = r + x_c;
			}
			Point positive = FindClosest(x, y);
			y = -sqrt(m) + y_c;
			x = -sqrt(m) * (double)(x_0 - x_c) / (double)(y_0 - y_c) + x_c;
			if (x_c == x_0)
			{
				y = -r + y_c;
				x = x_c;
			}
			if (y_c == y_0)
			{
				y = y_c;
				x = -r + x_c;
			}

			Point negative = FindClosest(x, y);
			if (CalcSquareDistance(x_0, y_0, positive.x, positive.y) < CalcSquareDistance(x_0, y_0, negative.x, negative.y))
				cout << positive.x << " " << positive.y << endl;
			else
				cout << negative.x << " " << negative.y << endl;
		}
	}
}