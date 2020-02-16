
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

bool Has(vector<int> v, int val)
{
    for (int i = 0; i < v.size(); i++)
        if (v[i] == val)
            return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> players;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        players.push_back(num);
    }
    int res = 1;
    int countFirst = 0;
    int countSecond = 0;
    for (int i = 1; i <= 2*n; i++)
    {
        if(countFirst < n && countSecond < n && i != 1)
            res *= 2;
        if (Has(players, i))
            countFirst++;
        else
            countSecond++;
    }
        
    cout << "1 " << res << endl;
}