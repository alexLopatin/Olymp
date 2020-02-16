
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int FindNumber(int n)
{
    int res = 0;
    for (int i = 2; i <=n; i++)
        if (n % i == 0)
            res++;
    return res;
}

int main()
{
    map<int, int, std::greater<int> > degrees;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        degrees[d]++;
    }
    map<int, int>::iterator it;
    int residue = 0;
    for (it = degrees.begin(); it != degrees.end(); it++)
    {
        int degree = it->first;
        int coef = it->second;
        residue += coef *( (degree % 2 == 0) ? (1) : (-1));
    }
    if (residue == 0)
        cout << "-1\n";
    else
        cout << FindNumber(abs(residue)) << endl;
}