#include <iostream>
#include <math.h>
#include <map>

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	map<int, int> preferences;
	for (int i = 0; i < n; i++)
		preferences[i] = 0;
	for (int i = 0; i < k; i++)
	{
		int player, pref;
		cin >> player >> pref;
		player--;
		preferences[player] = preferences[player] | (1 << (pref - 1));
	}
	map<int, int> players;
	for (int j = 0; j < 32; j++)
	{
		players[j] = 0;
		for (int i = 0; i < n; i++)
		{
			if ((j & preferences[i]) == 0)
				players[j]++;
		}
	}
	int res = -1;
	for (int i = 0; i < 32; i++)
	{
		if (players[i] > res&& players[i] <= m)
			res = players[i];
	}
	if (res >= 0)
		cout << res << endl;
	else
		cout << "Round will be unrated\n";
	return 0;
}