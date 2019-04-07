#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k, h;
int max_step = 10000;
bool printornot = false;
int steps[30][10];

int forward(int node)
{
	int cur_node = node;
	for (int i = 0; i < h; i++)
	{	
		if(steps[i][cur_node]==1 && cur_node < n - 1)
			cur_node = cur_node + 1;
		else if (cur_node >= 1)
		{
			if (steps[i][cur_node - 1] == 1)
				cur_node = cur_node - 1;
		}
	}
	return cur_node;
}

void find_ladder(int step, int limit, pair<int, int> prev_added)
{

	if (limit >= 0)
	{
		//cout << "===========================" << endl;
		//cout << prev_added.first << " " << prev_added.second << " " << step << endl;
		//for (int l = 0; l < h; l++)
		//{
		//	for (int u = 0; u < n; u++)
		//	{
		//		cout << steps[l][u] << " ";
		//	}
		//	cout << endl;
		//}
		for (int j2 = 0; j2 < n; j2++)
		{

			int result = forward(j2);
			//if (prev_added.first == 5 && prev_added.second == 3)
			//	cout << "result : " << result << " " << j2 << endl;
			if (j2 != result)
				break;
			if (j2 == n - 1)
			{
				cout << step << endl;
				printornot = true;
				return;
			}
		}

		for (int i = prev_added.first; i < h; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				bool flag = false;
				if (steps[i][j] == 1)
				{
					j++;
					continue;
				}
				if (j < n - 1)
				{
					if (steps[i][j + 1] == 1)
					{
						j = j + 2;
						continue;
					}
				}
				if (limit >= 0)
				{
					
					steps[i][j] = 1;
					find_ladder(step + 1, limit - 1, make_pair(i, j));
					steps[i][j] = 0;
					if (printornot)
						return;
				}
			}
		}
	}
	else
		return;
}

int main()
{
	scanf("%d %d %d", &n, &k, &h);

	for (int i = 0; i < k; i++)
	{
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		steps[tmp1 - 1][tmp2 - 1] = 1;
	}
	int cnt = 0;
	int limit = 0;
	//for (int i = 0; i < 4; i++)
	//{
		find_ladder(cnt, 3, make_pair(0, 0));
		//if (printornot)
			//break;
	//}
	
	if (!printornot)
		cout << -1 << endl;

	return 0;

}