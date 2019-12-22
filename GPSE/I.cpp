
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Data {
    int index;
    int length;
};
int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;
    for( int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    for( int i = 0; i < n; i++) {
        int t;
        cin >> t;
        b.push_back(t);
    }

    int min = 1000000000;
    int max = 1;
    int k = 0;

    while(a.size() > 1 || b.size() > 1) {
        if(k % 2 == 0) {
            multimap<int, int> lengthSort;
            for(int i = 0; i < a.size(); i++) {
                for(int j = 0; j < b.size(); j++) {
                    lengthSort.insert(pair<int, int> (abs(a[i] - b[j]), i));
                }
            }
            min = lengthSort.begin()->first;
            multimap<int, int>::iterator itr;
            map<int, int> countSort;
            for(itr = lengthSort.begin(); itr != lengthSort.end(); ++itr) {
                if(itr->first != min) {
                    break;
                }
                countSort[itr->second]++;
            }
            map<int, int>::iterator itr1;
            int maxIndex = 0;
            int max0 = 1;
            for(itr1 = countSort.begin(); itr1 != countSort.end(); ++itr1) {
                if(itr1->second > max0) {
                    max0 = itr1->second;
                    maxIndex = itr1->first;
                }
            }
            a.erase(a.begin() + maxIndex);
            
        }
        else {
            multimap<int, int, greater<int> > lengthSort;
            for(int i = 0; i < a.size(); i++) {
                for(int j = 0; j < b.size(); j++) {
                    lengthSort.insert(pair<int, int> (abs(a[i] - b[j]), i));
                }
            }
            max = lengthSort.begin()->first;
            multimap<int, int>::iterator itr;
            map<int, int> countSort;
            for(itr = lengthSort.begin(); itr != lengthSort.end(); ++itr) {
                if(itr->first != max) {
                    break;
                }
                countSort[itr->second]++;
            }
            map<int, int>::iterator itr1;
            int maxIndex = 0;
            int max0 = 1;
            for(itr1 = countSort.begin(); itr1 != countSort.end(); ++itr1) {
                if(itr1->second > max0) {
                    max0 = itr1->second;
                    maxIndex = itr1->first;
                }
            }
            b.erase(b.begin() + maxIndex);
            
        }
        k++;
    }
    cout << abs(a[0] - b[0]) << endl;
}