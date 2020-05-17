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
	vector<int> a;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		a.push_back(num);
	}
	int ans = a[0],
		ans_l = 0,
		ans_r = 0,
		sum = 0,
		min_sum = 0,
		min_pos = -1;
	for (int r = 0; r < n; ++r) {
		sum += a[r];

		int cur = sum - min_sum;
		if (cur > ans) {
			ans = cur;
			ans_l = min_pos + 1;
			ans_r = r;
		}

		if (sum < min_sum) {
			min_sum = sum;
			min_pos = r;
		}
	}
	cout << ans_l + 1 << " " << ans_r + 1 << endl;
	return 0;
}