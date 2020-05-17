
#include <iostream>
#include <math.h>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> nums;
    vector<string> history;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        history.push_back(s);
        sort(s.begin(), s.end());
        nums[s]++;
    }
    int Max = 0;
    for (map<string, int>::iterator it = nums.begin(); it != nums.end(); it++)
        if (Max < it->second)
            Max = it->second;

    unsigned int place = n;

    for (map<string, int>::iterator it = nums.begin(); it != nums.end(); it++)
        if (Max == it->second)
        {
            for (unsigned int i = 0; i < (unsigned int)n; i++)
            {
                string s = history[i];
                sort(s.begin(), s.end());
                if (strcmp(s.c_str(), it->first.c_str()) == 0 && place > i)
                    place = i;

            }
        }
            

    string s = history[place];
    cout << s << " ";
    sort(s.begin(), s.end());
    cout << nums[s] - 1<< endl;

    return 0;
}