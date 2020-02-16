
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int FindNumber(int n)
{
    int res = 0;
    for (int i = 2; i <= ceil( sqrt(n)); i++)
        if (n % i == 0)
            res++;
    if (n != 1)
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
    map<int, int>::iterator it, next;
    if(degrees[0] == 0)
        degrees[0] = 0;
    for (it = degrees.begin(); it != degrees.end(); it++)
    {
        int degree = it->first;
        int coef = it->second;
        next = it;
        next++;
        if (next == degrees.end())
            break;
        if (coef == 0)
            continue;
        int nextDegree = next->first;
        int nextCoef = next->second;
        if (degree == nextDegree + 1)
            degrees[nextDegree] = nextCoef - coef;
        else
            degrees[degree - 1] = -coef;
    }
    if (degrees[0] == 0)
        cout << "-1\n";
    else
        cout << FindNumber(abs(degrees[0])) << endl;
}
