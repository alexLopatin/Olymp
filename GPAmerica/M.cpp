#include <iostream>
#include <math.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


int main()
{
    vector<int> fib(26);
    fib[0] = 1;
    fib[1] = 3;
    fib[2] = 3;
    fib[3] = 5;
    fib[4] = 5;
    fib[5] = 5;
    fib[6] = 7;
    fib[7] = 7;
    fib[8] = 7;
    fib[9] = 7;
    fib[10] = 7;
    fib[11] = 9;
    fib[12] = 9;
    fib[13] = 9;
    fib[14] = 9;
    fib[15] = 9;
    fib[16] = 9;
    fib[17] = 9;
    fib[18] = 9;
    fib[19] = 11;
    fib[20] = 11;
    fib[21] = 11;
    fib[22] = 11;
    fib[23] = 11;
    fib[24] = 11;
    fib[25] = 11;
	string text;
	//cin >> text;
	getline(cin, text);
	map<char, int> freq;
	int size = 0;
	
	for (unsigned int i = 0; i < text.size(); i++)
        if (isalpha(text[i]))
        {
		    size++;
		    freq[tolower(text[i])] ++;
	    }
			

	multimap<int, char, greater<int> > invFreq;
	map<char, int>::iterator it;
	
	for (it = freq.begin(); it != freq.end(); it++)
		invFreq.insert(pair<int, char>(it->second , it->first));
		
	multimap<int, char>::iterator itr;
	int curIndex = 0;
	int res = 0;
	vector<int> codes;
	for (itr = invFreq.begin(); itr != invFreq.end(); itr++)
	{
	    
		res += itr->first * fib[curIndex];
		curIndex++;
	}
	if(size > 0)
	res += (size - 1) * 3;
	cout << res << endl;
 	return 0;
}