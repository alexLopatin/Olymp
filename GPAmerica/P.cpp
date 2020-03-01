#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string alp;
    string s2;
    set <string> myset;
    cin >> alp;
    cin >> s2;
    for(int i = 0; i < (int)s2.size(); i++){
        for(int j =0; j < (int)alp.size(); j++){
            char a = alp[j];
            string s = s2;
            s[i] = a;
            myset.insert(s);
        }
    }
    for(int i = 0; i < (int)s2.size() + 1; i++){
        for(int j = 0; j < (int)alp.size(); j++){
            char a = alp[j];
            string s1 = s2;
            s1.insert(i, 1, a);
            myset.insert(s1);
        }
    }
    for(int i = 0; i < (int)s2.size(); i++){
        for(int j = 0; j < (int)alp.size(); j++){
            char a = alp[j];
            string s1 = s2;
            s1.erase(i, 1);
            myset.insert(s1);
        }
    }
    myset.erase(s2);
    set<string>::iterator it;
    for( it = myset.begin(); it != myset.end(); it++)
        cout << *it << endl;
}