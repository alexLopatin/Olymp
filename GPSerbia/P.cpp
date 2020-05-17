
#include <iostream>
#include <math.h>


using namespace std;

int length(long long n)
{
    int i = 0;
    if (n == 0)
        i++;
    while (n > 0)
    {
        int d = n % 10;
        n /= 10;
        i++;
    }
    return i;
}

long long max(long long a, long long b)
{
    if (a > b)
        return a;
    return b;
}
int main()
{
    long long n;
    cin >> n;
    long long res = 1;
    long long n1 = n;
    while (n1 > 0)
    {
        res *= n1 % 10;
        n1 /= 10;
    }
    int i = 0;
    int l = length(n);
    long long cur = 1;
    while (n > 0)
    {
        long long d = n/ pow(10, length(n) - 1);
        n = n % (long long)pow(10, length(n) - 1);
        i++;
        res = max(res, cur * max((d-1),1) * pow(9, l - i));
        cur *= d;
    }
    cout << res << endl;
}