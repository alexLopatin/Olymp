
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

vector< vector<int> > getAllSubsets(vector<int> set)
{
    vector< vector<int> > subset;
    vector<int> empty;
    subset.push_back(empty);

    for (int i = 0; i < set.size(); i++)
    {
        vector< vector<int> > subsetTemp = subset;  //making a copy of given 2-d vector.

        for (int j = 0; j < subsetTemp.size(); j++)
            subsetTemp[j].push_back(set[i]);   // adding set[i] element to each subset of subsetTemp. like adding {2}(in 2nd iteration  to {{},{1}} which gives {{2},{1,2}}.

        for (int j = 0; j < subsetTemp.size(); j++)
            subset.push_back(subsetTemp[j]);  //now adding modified subsetTemp to original subset (before{{},{1}} , after{{},{1},{2},{1,2}}) 
    }
    return subset;
}

int main()
{
    int n;
    cin >> n;
    vector<int> chars;
    //chars.erase(remove(chars.begin(), chars.end(), 'a'), chars.end());
    for (int i = 0; i < n; i++)
        chars.push_back(i);

    auto subsets = getAllSubsets(chars);
    for (int i = 0; i < subsets.size(); i++)
    {
        auto subset = subsets[i];
        vector<int> secondSubset = chars;
        for (int i = 0; i < subset.size(); i++)
        {
            //cout << (char)(subset[i]+'a');
            secondSubset.erase(remove(secondSubset.begin(), secondSubset.end(), subset[i]), secondSubset.end());
        }
        cout << " ";
        for (int i = 0; i < secondSubset.size(); i++)
            i = i;
            //cout << (char)(secondSubset[i] + 'a');
        //cout << endl;
    }
    cin >> n;
}
