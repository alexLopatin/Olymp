#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
    long long int S;
    while(cin >> S) {
    	if(S == 0)
    		return 0;
    	long long n = ceil((-1 + sqrt(1 + 8 * S))/2);
    	long long curSum = n*(n + 1)/2;
    	if(curSum == S) {
    		cout << "-1\n";
    	}
    	else
    		cout << curSum - S << endl;
    }
}