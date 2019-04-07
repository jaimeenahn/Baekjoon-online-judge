#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool chk[21];
int min_diff = 400000;
int stats[21][21];


void dfs(int node, int cnt)
{
	if (cnt == n / 2)
	{
		int team1_score = 0;
		int team2_score = 0;
		vector<int> team1;
		vector<int> team2;
		for (int i = 0; i < n; i++)
		{
			if (chk[i] == false)
				team1.push_back(i);
			else
				team2.push_back(i);
		}
		for (int i = 0; i < team1.size(); i++)
		{
			for (int j = i + 1; j < team1.size(); j++)
			{
				team1_score += (stats[team1[i]][team1[j]] + stats[team1[j]][team1[i]]);
			}
		}

		for (int i = 0; i < team2.size(); i++)
		{
			for (int j = i + 1; j < team2.size(); j++)
			{
				team2_score += (stats[team2[i]][team2[j]] + stats[team2[j]][team2[i]]);
			}
		}
		if (abs(team1_score - team2_score) < min_diff)
			min_diff = abs(team1_score - team2_score);
	}
	for (int i = node; i < n; i++)
	{
		if (chk[i] == false)
		{
			chk[i] = true;
			dfs(i, cnt + 1);
			chk[i] = false;
		}
	}

}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &stats[i][j]);
		}
	}
	chk[0] = true;
	dfs(0, 1);

	cout << min_diff << endl;

	return 0;


}