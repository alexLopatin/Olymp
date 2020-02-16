#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int main()
{
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if ((r1 < l2 && r1 < r2 ) || (r2 < l1 && r2 < r1))
        cout << "2 " << r1 << " " << l2 << endl;
    else if (r2 >= l1 && r2 <= r1 )
        cout << "1 " << r2 << endl;
    else if (r1 >= l2 && r1 <= r2)
        cout << "1 " << r1 << endl;
}
