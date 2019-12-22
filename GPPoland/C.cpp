#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	long long n, k;
	cin >> n >> k;
	while(true) {
		int p = n % 10;
		if(p == k && n % k == 0) {
			cout << n << endl;
			return 0;
		}
		else {
			n++;
		}
	}
}