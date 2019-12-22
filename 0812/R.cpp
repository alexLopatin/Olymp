
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
    	multimap<int, string, greater<int> > players;
    	int p;
    	cin >> p;
    	for(int j = 0; j < p; j++) {
    		string name;
	    	int price;
	    	cin >> price >> name;
	    	players.insert(pair<int, string>(price, name));
    	}
    	cout << players.begin()->second << endl;
    }
}

