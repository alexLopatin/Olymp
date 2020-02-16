#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;
	vector<int> C;
	C.push_back(1);
	for (int i = 0; i < n; i++)
	{
		int C_i = 0;
		for (int j = 0; j < i + 1 ; j++)
			if(j - (i-j) <=k)
				C_i = ((C[j] * C[i - j]) % 998244353 + C_i) % 998244353;
		C.push_back(C_i);
	}
	cout << C[n - 1] << endl;
}