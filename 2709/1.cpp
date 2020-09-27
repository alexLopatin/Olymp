#include <iostream>

using namespace std;

#define ll long long

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		ll N, M, R, C, S;
		cin >> N >> M >> R >> C >> S;

		cout << (((C - S > 1 && R + S < N) || (R - S > 1 && C + S < M))
			? "Barsik\n"
			: "Tuzik\n");
	}
}