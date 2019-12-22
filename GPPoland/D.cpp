#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	int R1, R2, R3;
	cin >> R1 >> R2 >> R3;
	double p = (R1 + R2 + R3);
	double res = sqrt((p - R1 - R2) * (p - R2 - R3) * (p - R1 - R3) / p);
	cout << res << endl;
}
