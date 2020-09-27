#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int n;
vector<int> g[200];
bool used[200];
vector<int> comp;

ll result = 0;

void dfs(int v) {
	used[v] = true;
	comp.push_back(v);
	for (size_t i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs(to);
	}
}

void find_comps() {
	for (int i = 0; i < n; ++i)
		used[i] = false;
	for (int i = 0; i < n; ++i)
		if (!used[i]) {
			comp.clear();
			dfs(i);

			result += comp.size() - 1;
		}
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> n;
		result = 0;

		for (int i = 0; i < n; i++)
		{
			g[i] = vector<int>();

			for (int j = 0; j < n; j++)
			{
				int p;
				cin >> p;

				if (p)
				{
					g[i].push_back(j);
				}
			}
		}

		for (int j = 0; j < 200; j++)
		{
			used[j] = 0;
		}

		find_comps();

		cout << result << endl;
	}
}