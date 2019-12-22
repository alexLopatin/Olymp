#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

long long Sum(int n) {
	long long res = 0;
	for(int i = 1; i <= n - 3; i++) {
		res += i;
	}
	return res;
}

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	if(n > 3)
		cout << Sum(n) + 1 << endl;
	for(int i = 1; i <= n - 2; i++) {
		for(int j = i + 1; j <= n - 2; j++) {
			cout << i << ' ' << j << endl;
		}
	}
	if(n > 3)
		cout << n - 1 << ' ' << n << endl;
	else 
		cout << 0 << endl;
}
