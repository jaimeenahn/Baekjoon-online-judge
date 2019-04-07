#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
팀 능력치는 += Sij = Sji
조합 : 
*/
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> people;
	int stat[21][21];
	for (int i = 0; i < n; i++)
	{
		people.push_back(i + 1);
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &stat[i + 1][j + 1]);
		}
	}
	int min_diff = 400000;
	vector<int> idx;
	for (int i = 0; i < n/2; i++)
	{
		idx.push_back(1);
	}
	for (int i = 0; i < n/2; i++)
	{
		idx.push_back(0);
	}
	sort(idx.begin(), idx.end());
	do
	{
		int team1 = 0;
		int team2 = 0;
		vector<int> team_1;
		vector<int> team_2;
		for (int x = 0; x < n; x++)
		{
			if (idx[x] == 0)
				team_1.push_back(people[x]);
			else
				team_2.push_back(people[x]);

		}

		for (int i = 0; i < team_1.size(); i++)
		{
			for (int j = i + 1; j < team_1.size(); j++)
			{
				team1 += (stat[team_1[i]][team_1[j]] + stat[team_1[j]][team_1[i]]);
			}
		}

		for (int i = 0; i < team_2.size(); i++)
		{
			for (int j = i + 1; j < team_2.size(); j++)
			{
				team2 += (stat[team_2[i]][team_2[j]] + stat[team_2[j]][team_2[i]]);
			}
		}
		if (abs(team1 - team2) < min_diff)
			min_diff = abs(team1 - team2);

	} while (next_permutation(idx.begin(), idx.end()));

	cout << min_diff << endl;
	return 0;
}