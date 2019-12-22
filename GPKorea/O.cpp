#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
  set<string> monument;
  string s;
  while (getline(cin,s)) {
    s.erase(s.begin(), s.begin() + 11);
    monument.insert(s);
  }
  cout << monument.size();
}