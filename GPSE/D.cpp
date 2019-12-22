
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    char str;
    vector <int> sim(26);
    for (int i = 0; i < 26; i++)
        sim[i] = 0;
    int i = 0;
    while (cin >> str) {
        if ((str >= 'a')&(str <= 'z')) {
            sim[str - 'a']++;
        }
        i++;
    }
    int n = i / 2;
    for (i = 0; i < 26; i++) {
        if (sim[i] > n) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    for (i = 0; i < 26; i++) {
        char k = 'a' + i;
        for (int i2 = 0; i2 < sim[i]; i2++) {
            cout << k;
        }
    }
    cout << endl;
}