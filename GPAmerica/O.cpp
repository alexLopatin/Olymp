//Ксюша Бондарь
#include <iostream>

using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;
    long long a1 = 1;
    long long a2 = 2;
    unsigned long long s1 = a1 * n + n * (n - 1) / 2;
    unsigned long long s2 = a2 * n + n * (n - 1) / 2;
    if(s1 % 2 == s2 % 2){
        if (s1 % 2 == 0) cout << "2";
        else cout << "1";
    }
    else cout << "0";
}