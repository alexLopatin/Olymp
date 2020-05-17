#include <iostream>
#include <math.h>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

unsigned long long lcm(unsigned long long a, unsigned long long b) {
	return a / gcd(a, b) * b;
}

const unsigned long long constraint = 1000000 * 1000000 * 1000000;

int main()
{
	int n;
	cin >> n;
	vector<int> A;
	A.push_back(1);
	for (int i = 0; i < n - 1; i++)
	{
		int num;
		cin >> num;
		A.push_back(num);
	}
	A.push_back(1);
	vector<unsigned long long> L;
	for (int i = 1; i < n + 1; i++)
	{
		L.push_back(lcm(A[i - 1], A[i]));
		if ((i > 1 && gcd(L[i - 1], L[i - 2]) != A[i - 1]) || L[i - 1] >= constraint)
		{
			cout << "-1\n";
			return 0;
		}
	}

	for (unsigned int i = 0; i < L.size(); i++)
		cout << L[i] << " ";
	cout << endl;
	return 0;
}