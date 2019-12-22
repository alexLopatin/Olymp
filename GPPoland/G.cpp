#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstring>
using namespace std;

struct NUM {
	std::vector<int> digits;
	int dot;
	int size;
    bool operator< (const NUM &b) const
	{
		if(dot != b.dot) 
			return dot < b.dot;
	    for(int i = 0; i < 1000; i++) {
        	if(digits[i] < b.digits[i]) {
        		return true;
        	}
        	if (digits[i] > b.digits[i]) {
        		return false;
        	}
        }
        return false;
	}
};

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	vector<NUM> numbers;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		NUM num;
		num.digits.resize(1000, 0);
		int b = 0;
		for(int j = 0; j < (int)s.length(); j++) {
			if(s[j] == '.') {
				num.dot = j;
				if(j == 0) {
					num.digits[0] = 0;
				}
				b = 1;
			}
			else {
				num.digits[j - b] = s[j] - '0';
			}
		}
		num.size = s.length() - 1;
		numbers.push_back(num);
	}
	sort(numbers.begin(), numbers.end());
	k = n - k;
	for(int j = 0; j < (int)numbers[k].size; j++) {
		if(j == numbers[k].dot) {
			cout << '.';
		}
		cout << numbers[k].digits[j];
	}
	if(numbers[k].dot == numbers[k].size) 
		cout << '.';
	cout << endl;
}
